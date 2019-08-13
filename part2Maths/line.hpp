
#ifndef line_hpp
#define line_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "ResourcePath.hpp"

class line {
    
    //line is made of one thin rectangle before rotating point and an other after
    sf::RectangleShape mRecBefore;
    sf::RectangleShape mRecAfter;
    
    sf::Font mFont;
    sf::Text mText;
    
    //cartesian equation parameters ax+by+c=0
    float mA, mB, mC;
    
    //length of screen diagonaly in pixels
    unsigned mDiagonale;
    
    //on off rotation
    bool mRotate;
    
    sf::RenderWindow& mWin;
    bool mTestMode;
    
    //private fonction calcul a second point of line to calcul cartesian equation
    sf::Vector2f findSecondPt() const;
    
public:
    line(sf::RenderWindow& win, sf::Vector2f const xy);
    
    //turn line a little 0.1 degree
    void rotate();
    
    //set line rotation starting point
    void setStartingPt(int const x, int const y);
    void setStartingPt(sf::Vector2f const xy);
    
    //get line rotation starting point
    sf::Vector2f getStartingPt() const;
    
    //calcul cartesian equation parameters ax+by+c=0
    void calculEquationDroite();
    
    void resetRotation();
    
    void drawLine() const;
    
    //turn on and off rotation
    void onOffRotate();
    
    //get cartesian equation parameters ax+by+c=0
    float getA() const;
    float getB() const;
    float getC() const;

};

#endif /* line_hpp */
