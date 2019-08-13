
#include "pts.hpp"

pts::pts(sf::RenderWindow& win, line& line): mWin(win), mLine(line){
    //loading font and sound
    if(!mFont.loadFromFile(resourcePath() + "sansation.ttf")){
        return EXIT_FAILURE;
    }
    if(!mBuffer.loadFromFile(resourcePath() + "click.wav")){
        return EXIT_FAILURE;
    }
    mSound.setBuffer(mBuffer);
    
}

//draw points depending how far the line is (aspect of a point change if line less than 6pixels and again if less than 3pixels)
void pts::drawPts(){
    //distance beteween one point and the line
    float distance;
    //this circle represent every point, it is moved and drawn multiple times
    sf::CircleShape c(6);
    c.setOrigin(6, 6);
    c.setOutlineThickness(2);
    
    //for each point in point vector
    for(pt& point : mPoints){
        
        //reseting circle apparence
        c.setOrigin(6, 6);
        c.setRadius(6);
        c.setFillColor(sf::Color::Green);
        //calculing distance betwen curent point and line quick math
        distance = abs(mLine.getA()*point.mXy.x + mLine.getB()*point.mXy.y + mLine.getC()) / sqrt(mLine.getA()*mLine.getA()+mLine.getB()*mLine.getB());
        
        if(distance <= 6){
            
            //change apparence if 3 > distance > 6
            c.setOrigin(8, 8);
            c.setRadius(8);
            
            if(distance < 3){
                
                if(point.mSelectable == true){
                    //if point selectable and close enough play sound and change line starting point
                    mSound.play();
                    mLine.setStartingPt((sf::Vector2f)point.mXy);
                    
                    //point is nolonger selectable until line get at least 6pixels away
                    point.mSelectable = false;
                    //add one to number of interaction line point count
                    point.plusOne();
                }
                
                c.setFillColor(sf::Color::Red);

            }
            
        }else if(distance > 6){
            //if distance > 6 set the point to be selectable
            point.mSelectable = true;
            
        }
        
        c.setPosition((sf::Vector2f)point.mXy);
        mWin.draw(c);
        point.setText();
        point.mText.setFont(mFont);
        mWin.draw(point.mText);
        
    }
    
}

void pts::addPt(sf::Vector2i const xy){
    
    //create point at the back of the point vector
    mPoints.emplace_back(pt(sf::Vector2i(xy), false));

}

bool pts::ready() const{
    return mPoints.size()>0;
}


