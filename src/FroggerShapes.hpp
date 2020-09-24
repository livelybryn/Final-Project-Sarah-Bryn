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
    sf::CircleShape frogShape;
    
private:
    int xAxis;
    int yAxis;
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
    vector<Cars> createTrack1 ();
    vector<Cars> createTrack2 ();
    vector<Cars> createTrack3 ();
    void moveCar(int rand);
    void moveCarOpp (int rand);
    void resetCar(int x, int y);
    float carXAxis ();
    sf::RectangleShape carShape;
    
private:
    int speed;

};

class World {
public:
    void updateCarMove ();
    void updateCarSpeed ();
    void globalBounds(Frog& frog, vector<Cars>& car);
    
private:

    
};

void globalBounds(Frog& frog, vector<Cars>& vc1, vector<Cars>& vc2, vector<Cars>& vc3) {
    for (int i=0; i < vc3.size(); i++) {
        if (frog.frogShape.getGlobalBounds().intersects(vc1[i].carShape.getGlobalBounds()) || frog.frogShape.getGlobalBounds().intersects(vc2[i].carShape.getGlobalBounds()) || frog.frogShape.getGlobalBounds().intersects(vc3[i].carShape.getGlobalBounds())) {
            frog.frogShape.setPosition(375, 550);
            for (int x=0; x < vc1.size(); x++) {
                vc1[x].carShape.setPosition(x*225, 450);
            }
            for (int x=0; x < vc2.size(); x++) {
                vc2[x].carShape.setPosition(x*300, 300);
            }
            for (int x=0; x < vc3.size(); x++) {
                vc3[x].carShape.setPosition(x*275, 150);
            }
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

vector<Cars> Cars::createTrack1 () {
    vector<Cars> carVector = {};
    Cars car;
    for (int i=0; i<3; i++) {
        car.speed = 3;
        car.carShape.setPosition(i*225, 450);
        car.carShape.setFillColor(sf::Color(rand()%255, rand()%255, rand()%255));
        carVector.push_back (car);
    }
    return carVector;
}

vector<Cars> Cars::createTrack2 () {
    vector<Cars> carVector2 = {};
    Cars car2;
    for (int i=0; i<3; i++) {
        car2.speed = 4;
        car2.carShape.setPosition(i*300, 300);
        car2.carShape.setFillColor(sf::Color(rand()%255, rand()%255, rand()%255));
        carVector2.push_back (car2);
    }
    return carVector2;
}

vector<Cars> Cars::createTrack3 () {
    vector<Cars> carVector3 = {};
    Cars car3;
    for (int i=0; i<4; i++) {
        car3.speed = 5;
        car3.carShape.setPosition(i*275, 150);
        car3.carShape.setFillColor(sf::Color(rand()%255, rand()%255, rand()%255));
        carVector3.push_back (car3);
    }
    return carVector3;
}

void Cars::moveCar(int rand) {
    carShape.move(1 * speed * rand, 0);
}

void Cars::moveCarOpp (int rand) {
    carShape.move(-1 * speed * rand, 0);
}

void Cars::resetCar(int x, int y) {
    carShape.setPosition(x, y);
}

float Cars::carXAxis () {
    return carShape.getPosition().x;
}

#endif /* FroggerShapes_hpp */
