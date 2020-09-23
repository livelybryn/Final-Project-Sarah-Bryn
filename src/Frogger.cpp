#include <SFML/Graphics.hpp>
#include <iostream>
#include "FroggerShapes.hpp"

int main()
{
    Frog frogger;
    Cars car;
    vector<Cars> carVector = car.createVector();

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    window.setFramerateLimit(60);
    
    while (window.isOpen())
    {
        
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            
            //Movement for the frog
            frogger.moveFrog();
            globalBounds(frogger, carVector);
            
        }
        

        //Movement for the cars
        for (int i=0; i<carVector.size(); i++) {
            if(carVector[i].getxAxis() > 800) {
                carVector[i].setxAxis(150);
            }
            carVector[i].moveCar(1);
        }
        
        // clear the window with black color
        window.clear(sf::Color::Black);

        //Draw frogger and the cars
        window.draw(frogger.getFrog());
        for (int i=0; i<carVector.size(); i++) {
            window.draw(carVector[i].getCar());
        }
        

	// end the current frame
        window.display();
    }

    return 0;
}
