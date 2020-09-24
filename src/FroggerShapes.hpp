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
    int setSpeed(int value);
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

void globalBounds(Frog& frog, vector<Cars>& vc1, vector<Cars>& vc2, vector<Cars>& vc3, int& intLevel) {
    for (int i=0; i < vc3.size(); i++) {
        if (frog.frogShape.getGlobalBounds().intersects(vc1[i].carShape.getGlobalBounds()) || frog.frogShape.getGlobalBounds().intersects(vc2[i].carShape.getGlobalBounds()) || frog.frogShape.getGlobalBounds().intersects(vc3[i].carShape.getGlobalBounds())) {
            frog.frogShape.setPosition(375, 550);
            for (int x=0; x < vc1.size(); x++) {
                vc1[x].setSpeed(3);
                vc1[x].carShape.setPosition(x*225, 425);
                vc1[x].carShape.setFillColor(sf::Color(rand()%255, rand()%255, rand()%255));
            }
            for (int x=0; x < vc2.size(); x++) {
                vc2[x].setSpeed(4);
                vc2[x].carShape.setPosition(x*300, 275);
                vc2[x].carShape.setFillColor(sf::Color(rand()%255, rand()%255, rand()%255));
            }
            for (int x=0; x < vc3.size(); x++) {
                vc3[x].setSpeed(3);
                vc3[x].carShape.setPosition(x*275, 125);
                vc3[x].carShape.setFillColor(sf::Color(rand()%255, rand()%255, rand()%255));
            }
            intLevel = 0;
        }
    }
}

void nextLevel(Frog& frog, vector<Cars>& vc1, vector<Cars>& vc2, vector<Cars>& vc3, int& intLevel) {
    if (frog.frogShape.getPosition().y <= 0) {
        frog.frogShape.setPosition(375, 550);
        for (int i=0; i<3; i++) {
            vc1[i].setSpeed(rand()%7);
            vc1[i].carShape.setPosition(i*225, 425);
            vc1[i].carShape.setFillColor(sf::Color(rand()%255, rand()%255, rand()%255)); // All levels past 1 have random car movements
        }
        for (int i=0; i<3; i++) {
            vc2[i].setSpeed(rand()%7);
            vc2[i].carShape.setPosition(i*300, 275);
            vc2[i].carShape.setFillColor(sf::Color(rand()%255, rand()%255, rand()%255)); // All levels past 1 have random car movements
        }
        for (int i=0; i<4; i++) {
            vc3[i].setSpeed(rand()%7);
            vc3[i].carShape.setPosition(i*275, 125);
            vc3[i].carShape.setFillColor(sf::Color(rand()%255, rand()%255, rand()%255)); // All levels past 1 have random car movements
        }
        intLevel++;
    }
}

//Creating Track #1
vector<Cars> Cars::createTrack1 () {
    vector<Cars> carVector = {};
    Cars car;
    for (int i=0; i<3; i++) {
        car.speed = 3;
        car.carShape.setPosition(i*225, 425);
        car.carShape.setFillColor(sf::Color(rand()%255, rand()%255, rand()%255)); //Each car is a ranom color
        carVector.push_back (car);
    }
    return carVector;
}
//Creating Track #2
vector<Cars> Cars::createTrack2 () {
    vector<Cars> carVector2 = {};
    Cars car2;
    for (int i=0; i<3; i++) {
        car2.speed = 4;
        car2.carShape.setPosition(i*300, 275);
        car2.carShape.setFillColor(sf::Color(rand()%255, rand()%255, rand()%255)); //Each car is a random color
        carVector2.push_back (car2);
    }
    return carVector2;
}
//Creating Track #3
vector<Cars> Cars::createTrack3 () {
    vector<Cars> carVector3 = {};
    Cars car3;
    for (int i=0; i<4; i++) {
        car3.speed = 3;
        car3.carShape.setPosition(i*275, 125);
        car3.carShape.setFillColor(sf::Color(rand()%255, rand()%255, rand()%255)); //Each car is a random color
        carVector3.push_back (car3);
    }
    return carVector3;
}

void Cars::moveCar(int rand) { //Give each rectangle car it's movement
    carShape.move(1 * speed * rand, 0);
}

void Cars::moveCarOpp (int rand) { //Give a car movement in opposite direction
    carShape.move(-1 * speed * rand, 0);
}

void Cars::resetCar(int x, int y) { //Reset position of rectangle car
    carShape.setPosition(x, y);
}

float Cars::carXAxis () { //Return a rectangle car's current x position
    return carShape.getPosition().x;
}

int Cars::setSpeed(int value) {
    return speed = value;
}


#endif /* FroggerShapes_hpp */
