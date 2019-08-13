
#ifndef pts_hpp
#define pts_hpp

#include <stdio.h>
#include <cmath>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "line.hpp"

typedef struct pt{
public:
    sf::Vector2i mXy;
    bool mSelectable;
    sf::Text mText;
    unsigned n;
    
    pt(sf::Vector2i xy, bool selectable) : mXy(xy), mSelectable(selectable), n(0){}
    
    void setText() {
        mText.setFillColor(sf::Color::White);
        mText.setOutlineColor(sf::Color::Black);
        mText.setOutlineThickness(1);
        mText.setPosition(mXy.x - 8, mXy.y - 40);
        mText.setCharacterSize(24);
        mText.setString(std::to_string(n));
    }
    
    void plusOne(){
        n++;
    }
    
}pt;

class pts{
    std::vector<pt> mPoints;
    sf::RenderWindow& mWin;
    line& mLine;
    sf::Font mFont;
    sf::SoundBuffer mBuffer;
    sf::Sound mSound;
    
public:
    pts(sf::RenderWindow& win, line& line);
    void drawPts();
    void addPt(sf::Vector2i const xy, bool const setStartingPtForLine);
    bool ready() const;
};

#endif /* pts_hpp */
