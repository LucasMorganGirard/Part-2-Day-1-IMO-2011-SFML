
/**
    vector of points
*/

#ifndef pts_hpp
#define pts_hpp

#include <stdio.h>
#include <cmath>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "line.hpp"

/**
    one point
*/

typedef struct pt{
public:
    sf::Vector2i mXy;   //where the point is
    bool mSelectable;   //bool making sure point is not reselected right after(few frames) being unselected
    sf::Text mText;     //n is displayed by mText
    unsigned n;         //number of time point hitted by line
    
    pt(sf::Vector2i xy, bool selectable) : mXy(xy), mSelectable(selectable), n(0){}
    
    //mText parameters
    void setText() {
        mText.setFillColor(sf::Color::White);
        mText.setOutlineColor(sf::Color::Black);
        mText.setOutlineThickness(1);
        mText.setPosition(mXy.x - 8, mXy.y - 40);
        mText.setCharacterSize(24);
        //upgrade n
        mText.setString(std::to_string(n));
    }
    
    //...
    void plusOne(){
        n++;
    }
    
}pt;

class pts{
    
    std::vector<pt> mPoints;
    sf::RenderWindow& mWin;
    line& mLine;
    
    //ressources
    sf::Font mFont;
    sf::SoundBuffer mBuffer;
    sf::Sound mSound;
    
public:
    pts(sf::RenderWindow& win, line& line);
    //draw one point
    void drawPts();
    //add one point where mouse is (P or SPACE)
    void addPt(sf::Vector2i const xy);
    //prog is ready if there is at least one point
    bool ready() const;
};

#endif /* pts_hpp */
