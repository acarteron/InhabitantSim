#include "Circle.hh"

Circle::Circle():mobile2d(){
  shape=std::make_shared<sf::CircleShape>(sf::CircleShape(10));
  shape->setPosition(900,700);
}
Circle::Circle(prologparse * plparse):mobile2d(plparse){
  shape=std::make_shared<sf::CircleShape>(sf::CircleShape(10));
  shape->setPosition(900,700);
}
Circle::Circle(int x,int y):mobile2d(){
  shape=std::make_shared<sf::CircleShape>(sf::CircleShape(10));
  shape->setPosition(x,y);
}
Circle::Circle(prologparse * plparse,int x, int y):mobile2d(plparse){
  shape=std::make_shared<sf::CircleShape>(sf::CircleShape(10));
  shape->setPosition(x,y);
}
float Circle::x(){
  return shape->getPosition().x;
}
float Circle::y(){
  return shape->getPosition().y;
}
float Circle::limLeft() {
  return x() /*- shape->getRadius()*/;
}
float Circle::limRight() {
  std::shared_ptr<sf::CircleShape> circle=std::dynamic_pointer_cast<sf::CircleShape>(shape);
  return x() + circle->getRadius()*2.f;
}
float Circle::limUp() {
  return y() /*- shape->getRadius()*/;
}
float Circle::limDown() {
  std::shared_ptr<sf::CircleShape> circle=std::dynamic_pointer_cast<sf::CircleShape>(shape);
  return y() + circle->getRadius()*2.f;
}
void Circle::moveLeft(){
  shape->move(-1, 0);
}
void Circle::moveRight(){
  shape->move(1, 0);
}
void Circle::moveUp(){
  shape->move(0, -1);
}
void Circle::moveDown(){
  shape->move(0, 1);
}
