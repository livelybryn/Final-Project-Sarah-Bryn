#include <SFML/Graphics.hpp>
#include <iostream>
#include "FroggerShapes.hpp"

int main()
{
    srand(time(nullptr));
    
    Frog frogger;
    Cars track, track2, track3;
    vector<Cars> carVector1 = track.createTrack1();
    vector<Cars> carVector2 = track2.createTrack2();
    vector<Cars> carVector3 = track3.createTrack3();

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    //Background from this website: https://code.tutsplus.com/tutorials/corona-sdk-build-a-frogger-inspired-game-interface-creation--mobile-16254
    
    sf::Texture background;
    background.loadFromFile("../../FroggerBackground.png");
    
    sf::Sprite sprite;
    sf::Vector2u size = background.getSize();
    sprite.setTexture(background);
    sprite.setOrigin(size.x / 500, size.y / 300);
    
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
            globalBounds(frogger, carVector1, carVector2, carVector3);
            
            window.draw(sprite);
            
        }
        

        //Movement for the cars
        for (int i=0; i<carVector1.size(); i++) {
            if(carVector1[i].carXAxis() > 800) {
                carVector1[i].resetCar(-120, 425);
                globalBounds(frogger, carVector1, carVector2, carVector3);
                carVector1[i].moveCar(1);
            }
            globalBounds(frogger, carVector1, carVector2, carVector3);
            carVector1[i].moveCar(1);
        }
        for (int i=0; i<carVector2.size(); i++) {
            if(carVector2[i].carXAxis() > 800) {
                carVector2[i].resetCar(-120, 275);
                carVector2[i].moveCar(1);
                globalBounds(frogger, carVector1, carVector2, carVector3);
            }
            globalBounds(frogger, carVector1, carVector2, carVector3);
            carVector2[i].moveCar(1);
        }
        for (int i=0; i<carVector3.size(); i++) {
            if(carVector3[i].carXAxis() > 800) {
                carVector3[i].resetCar(-120, 125);
                globalBounds(frogger, carVector1, carVector2, carVector3);
                carVector3[i].moveCar(1);
            }
            globalBounds(frogger, carVector1, carVector2, carVector3);
            carVector3[i].moveCar(1);
        }
        
        // clear the window with black color
        window.clear(sf::Color::Black);
        window.draw(sprite);

        //Draw frogger and the cars
        window.draw(frogger.getFrog());
        for (int i=0; i<carVector1.size(); i++) {
            window.draw(carVector1[i].getCar());
        }
        for (int i=0; i<carVector2.size(); i++) {
            window.draw(carVector2[i].getCar());
        }
        for (int i=0; i<carVector3.size(); i++) {
            window.draw(carVector3[i].getCar());
        }
        

	// end the current frame
        window.display();
    }

    return 0;
}
