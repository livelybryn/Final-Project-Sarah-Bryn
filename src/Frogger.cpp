#include <SFML/Graphics.hpp>
#include <iostream>
#include "FroggerShapes.hpp"

int main()
{
    srand(time(nullptr));
    
    sf::Font font;
    if (!font.loadFromFile("PrettyLily.ttf")) { // font file is saved in xcode --> debug folder
        std::cout << "Font didn't load" << std::endl;
        return 1;
    }
    sf::Text text;
    text.setFont(font);
    text.setString("Level");
    text.setCharacterSize(75);
    text.setPosition(650, -25);
    
    sf::Text level;
    level.setFont(font);
    int intLevel = 1;
    level.setString(std::to_string(intLevel));
    level.setCharacterSize(75);
    level.setPosition(700, 25);
    
    Frog frogger;
    Cars track, track2, track3;
    vector<Cars> carVector1 = track.createTrack1();
    vector<Cars> carVector2 = track2.createTrack2();
    vector<Cars> carVector3 = track3.createTrack3();

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    
    //Background from this website: https://code.tutsplus.com/tutorials/corona-sdk-build-a-frogger-inspired-game-interface-creation--mobile-16254
    
    //Read-in background as a texture
    sf::Texture background;
    background.loadFromFile("../../FroggerBackground.png");
    
    //Create sprite with the background texture
    sf::Sprite sprite;
    sf::Vector2u size = background.getSize();
    sprite.setTexture(background);
    sprite.setOrigin(size.x / 500, size.y / 300);
    
    window.setFramerateLimit(60);
    
    while (window.isOpen())
    {
        window.draw(text);
        window.draw(level);

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            
            //Movement for the frog
            if(event.type == sf::Event::KeyPressed){ // Moves the frog if a key is pressed
                            if(event.key.code == sf::Keyboard::W){
                                frogger.frogShape.move(sf::Vector2f(0,-35));
                            }
                            if(event.key.code == sf::Keyboard::S){
                                frogger.frogShape.move(sf::Vector2f(0,35));
                            }
                            if(event.key.code == sf::Keyboard::A){
                                frogger.frogShape.move(sf::Vector2f(-35,0));
                            }
                            if(event.key.code == sf::Keyboard::D){
                                frogger.frogShape.move(sf::Vector2f(35,0));
                            }
                        }
            globalBounds(frogger, carVector1, carVector2, carVector3, intLevel); // Collision detecter
            nextLevel(frogger, carVector1, carVector2, carVector3, intLevel); // Next level initiator
            
            //Set sprite as the background throughout the window loop
            window.draw(sprite);
            
        }
        

        //Movement for the cars
        for (int i=0; i<carVector1.size(); i++) {
            if(carVector1[i].carXAxis() > 800) {
                carVector1[i].resetCar(-120, 425);
                globalBounds(frogger, carVector1, carVector2, carVector3, intLevel);
                carVector1[i].moveCar(1);
            }
            globalBounds(frogger, carVector1, carVector2, carVector3, intLevel);
            carVector1[i].moveCar(1);
        }
        for (int i=0; i<carVector2.size(); i++) {
            if(carVector2[i].carXAxis() < -110) {
                carVector2[i].resetCar(920, 275);
                carVector2[i].moveCarOpp(1);
                globalBounds(frogger, carVector1, carVector2, carVector3, intLevel);
            }
            globalBounds(frogger, carVector1, carVector2, carVector3, intLevel);
            carVector2[i].moveCarOpp(1);
        }
        for (int i=0; i<carVector3.size(); i++) {
            if(carVector3[i].carXAxis() > 800) {
                carVector3[i].resetCar(-120, 125);
                globalBounds(frogger, carVector1, carVector2, carVector3, intLevel);
                carVector3[i].moveCar(1);
            }
            globalBounds(frogger, carVector1, carVector2, carVector3, intLevel);
            carVector3[i].moveCar(1);
        }
        
        // clear the window
        window.clear(sf::Color::Black);
        // Maintain sprite as the background outside of window loop
        window.draw(sprite);

        //Draw frogger, the cars, and text
        window.draw(text);
        level.setString(std::to_string(intLevel));
        window.draw(level);
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
