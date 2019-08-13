
/**
    problem 2 Day 1 "windmill" from 2011 IMO in C++ with SFML
    just for fun
 
    Lucas GIRARD 13/08/2019
    L2 info University of Nantes Sciences et Techniques
 
 SPACE : start/stop rotation
 LEFT CLICK : place a point and put the line on it
 P : place a point
 R : reset rotation
 L : place the line rotation centre where your mouse is
 ESC : close
 
 program start once the line is placed and at least one point is there
*/

/**
 FIX : colinearity of points is not checked and prevented, create pbs
*/

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "line.hpp"
#include "pts.hpp"

int main(int, char const**)
{
    sf::RenderWindow window(sf::VideoMode(1800, 1600), "SFML window", sf::Style::None);
    window.setFramerateLimit(300);
    
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    line line(window, sf::Vector2f(400, 300));
    pts pts(window, line);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P) {
                pts.addPt(sf::Mouse::getPosition(window));
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::L) {
                line.setStartingPt((sf::Vector2f)sf::Mouse::getPosition(window));
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R) {
                line.resetRotation();
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                if(pts.ready()){
                    line.onOffRotate();
                }
            }
            
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                pts.addPt(sf::Mouse::getPosition(window));
                line.setStartingPt((sf::Vector2f)sf::Mouse::getPosition(window));
            }
        }
        line.rotate();
        window.clear();
        line.drawLine();
        pts.drawPts();
        window.display();
    }

    return EXIT_SUCCESS;
}
