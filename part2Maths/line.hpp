
#ifndef line_hpp
#define line_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "ResourcePath.hpp"

class line {
    sf::RectangleShape mRecBefore;
    sf::RectangleShape mRecAfter;
    sf::Font mFont;
    sf::Text mText;
    float mA, mB, mC;
    unsigned mDiagonale;
    bool mRotate;
    sf::RenderWindow& mWin;
    sf::Vector2f findSecondPt() const;
    
public:
    line(sf::RenderWindow& win, sf::Vector2f const xy);
    ~line();
    void rotate();
    void setStartingPt(int const x, int const y);
    void setStartingPt(sf::Vector2f const xy);
    sf::Vector2f getStartingPt() const;
    void calculEquationDroite();
    void drawLine() const;
    void onOffRotate();
    float getA() const;
    float getB() const;
    float getC() const;

};

#endif /* line_hpp */
