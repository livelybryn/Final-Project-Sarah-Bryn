#include <SFML/Graphics.hpp>
#include <iostream>
#include "FroggerShapes.hpp"

int main()
{
    Frog frogger;
    Cars car;
    vector<Cars> carVector = car.createVector();
    
    sf::Clock clock;
    sf::Time time = clock.getElapsedTime();
    float elapsed = time.asSeconds();
    
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    window.setFramerateLimit(60);
    // run the program as long as the window is open
    while (window.isOpen())
    {
        sf::Time dt = clock.restart();
        
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            frogger.moveFrog();
            car.moveCar(elapsed);
            gameOver(frogger, carVector);
        }
        // clear the window with black color
        window.clear(sf::Color::Black);


        window.draw(frogger.getFrog());
        for (int i=0; i<carVector.size(); i++) {
            window.draw(carVector[i].getCar());
        }

	// end the current frame
        window.display();
    }

    return 0;
}
