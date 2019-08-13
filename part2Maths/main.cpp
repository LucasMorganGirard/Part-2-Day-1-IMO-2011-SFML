
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "line.hpp"
#include "pts.hpp"

int main(int, char const**)
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window", sf::Style::None);
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
                pts.addPt(sf::Mouse::getPosition(window), false);
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                if(pts.ready()){
                    line.onOffRotate();
                }
            }
            
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                pts.addPt(sf::Mouse::getPosition(window), true);
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
