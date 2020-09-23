//
//  FroggerShapes.hpp
//  Frogger
//
//  Created by Sarah Poole on 9/22/20.
//

#ifndef FroggerShapes_hpp
#define FroggerShapes_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace std;

class Frog {
public:
    //Constructor
    Frog () {
        
    frogShape.setRadius(25);
    frogShape.setFillColor(sf::Color(85,107,47));
    frogShape.setPosition(375, 550);
    }
    
    //Method
    void moveFrog ();
    sf::CircleShape getFrog () {
        return frogShape;
    }
    
private:
    int xAxis;
    int yAxis;
    sf::CircleShape frogShape;
};

class Cars {
public:
    //Constructor
    Cars () {
        
    carShape.setSize(sf::Vector2f(120, 50));
    carShape.setFillColor(sf::Color(135,206,250));
    carShape.setPosition(0, 450);
    carShape.move(0, 0);
    }
    
    //Method
    sf::RectangleShape getCar () {
        return carShape;
    }
    vector<Cars> createVector ();
    float getxAxis();
    float getyAxis();
    void setxAxis(float x);
    void setyAxis(float y);
    void moveCar(int rand);
    void resetCar(int y);
    float carXAxis ();
    
private:
    float xAxis;
    float yAxis;
    int speed;
    sf::RectangleShape carShape;
};

class World {
    friend class Frog;
    friend class Cars;
public:
    void updateCarMove ();
    void updateCarSpeed ();
    bool globalBounds(Frog frog, Cars car);
    void gameOver(Frog frog, Cars car);
    
private:

    
};

bool globalBounds(Frog frog, std::vector<Cars> vc) {
    for (int i=0; i<3; i++) {
        if (frog.getFrog().getGlobalBounds() == vc[i].getCar().getGlobalBounds()) {
            return true;
        }
    }
    return false;
}

void gameOver(Frog frog, std::vector<Cars> vc) {
    if (globalBounds(frog, vc) == true) {
        frog.getFrog().setPosition(0, 450);
        frog.getFrog().setFillColor(sf::Color(255,230,0));
        for (int i=0; i<3; i++) {
            vc[i].setxAxis(i*150);
            vc[i].setyAxis(450);
            vc[i].getCar().setPosition(vc[i].getxAxis(), vc[i].getyAxis());
        }
    }
}

void Frog:: moveFrog () {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        frogShape.move(-25, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        frogShape.move(25, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        frogShape.move(0, -25);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        frogShape.move(0, 25);
    }
}

vector<Cars> Cars::createVector () {
    vector<Cars> carVector = {};
    Cars car;
    for (int i=0; i<3; i++) {
//        car.xAxis = i*150;
//        car.yAxis = 450;
        car.speed = 1;
        car.carShape.setPosition(i*150, 450);
        carVector.push_back (car);
    }
    return carVector;
}

float Cars::getxAxis() {
    return xAxis;
}
float Cars::getyAxis() {
    return yAxis;
}

void Cars::setxAxis(float x) {
    xAxis = x;
}
void Cars::setyAxis(float y) {
    yAxis = y;
}

void Cars::moveCar(int rand) {
    carShape.move(1 * speed * rand, 0);
//    xAxis += 1 * speed * rand;
}

void Cars::resetCar(int y) {
    carShape.setPosition(150, y);
//    xAxis = 150;
}

float Cars::carXAxis () {
    return carShape.getPosition().x;
}

#endif /* FroggerShapes_hpp */
