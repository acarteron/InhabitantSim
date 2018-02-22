#include "still2d.hh"

still2d::~still2d(){};
float still2d::limLeft(){return x();}
float still2d::limRight(){return x();}
float still2d::limUp(){return y();}
float still2d::limDown(){return y();}
float still2d::x(){
    return shape->getPosition().x;
  }
float still2d::y(){return shape->getPosition().y;}
std::shared_ptr<sf::Shape> still2d::getStill(){return shape;}
