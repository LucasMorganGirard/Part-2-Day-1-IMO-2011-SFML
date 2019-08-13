
#include "pts.hpp"

pts::pts(sf::RenderWindow& win, line& line): mWin(win), mLine(line){
    if(!mFont.loadFromFile(resourcePath() + "sansation.ttf")){
        return EXIT_FAILURE;
    }
    if(!mBuffer.loadFromFile(resourcePath() + "click.wav")){
        return EXIT_FAILURE;
    }
    mSound.setBuffer(mBuffer);
}

void pts::drawPts(){
    float distance;
    sf::CircleShape c(6);
    c.setOrigin(6, 6);
    c.setOutlineThickness(2);
    for(pt& point : mPoints){
        c.setOrigin(6, 6);
        c.setRadius(6);
        c.setFillColor(sf::Color::Green);
        distance = abs(mLine.getA()*point.mXy.x + mLine.getB()*point.mXy.y + mLine.getC()) / sqrt(mLine.getA()*mLine.getA()+mLine.getB()*mLine.getB());
        if(distance <= 6 && distance > 2){
            c.setOrigin(8, 8);
            c.setRadius(8);
        }else if (distance < 3){
            if(point.mSelectable == true){
                mSound.play();
                mLine.setStartingPt((sf::Vector2f)point.mXy);
                point.mSelectable = false;
                point.plusOne();
            }
            c.setOrigin(8, 8);
            c.setRadius(8);
            c.setFillColor(sf::Color::Red);
        }else if(distance > 6){
            point.mSelectable = true;
        }
        c.setPosition((sf::Vector2f)point.mXy);
        mWin.draw(c);
        point.setText();
        point.mText.setFont(mFont);
        mWin.draw(point.mText);
    }
}

void pts::addPt(sf::Vector2i const xy, bool const setStartingPtForLine){
    mPoints.emplace_back(pt(sf::Vector2i(xy), false));
}

bool pts::ready() const{
    return mPoints.size()>0;
}


