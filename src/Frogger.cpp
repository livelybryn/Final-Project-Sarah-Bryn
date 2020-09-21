#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    
    sf::CircleShape shape(25.f);
    
    shape.setPosition(375.f, 550.f);

    window.setFramerateLimit(60);
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                shape.move(-50.f, 0.f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                shape.move(50.f, 0.f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                shape.move(0.f, -50.f);
            }
        }
        // clear the window with black color
        window.clear(sf::Color::Black);
        
                
// set the shape color to green
shape.setFillColor(sf::Color(135,206,250));

 window.draw(shape);
	// end the current frame
        window.display();
    }

    return 0;
}
