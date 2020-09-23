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
    sf::RectangleShape& getCar () {
        return carShape;
    }
    vector<Cars> createVector ();
    void moveCar(float elapsed);
    float getxAxis();
    float getyAxis();
    void setxAxis(float x);
    void setyAxis(float y);
    
private:
    float xAxis;
    float yAxis;
    int speed;
    sf::RectangleShape carShape;
};

class World {
public:
    void updateCarMove ();
    void updateCarSpeed ();
    
private:

    
};

void Frog:: moveFrog () {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        frogShape.move(-50, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        frogShape.move(50, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        frogShape.move(0, -50);
    }
}

vector<Cars> Cars::createVector () {
    vector<Cars> carVector = {};
    Cars car;
    for (int i=0; i<1; i++) {
        car.xAxis = i*150;
        car.yAxis = 450;
        car.speed = 100;
        car.carShape.setPosition(car.xAxis, car.yAxis);
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

}
void Cars::setyAxis(float y) {
    
}

void Cars::moveCar(float elapsed) {
    carShape.move(1 * speed * elapsed, 0);
}

#endif /* FroggerShapes_hpp */
