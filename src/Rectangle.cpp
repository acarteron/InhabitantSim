#include "Rectangle.hh"

Rectangle::Rectangle(float posx,float posy,
		     int width,int height){
  shape=std::make_shared<sf::RectangleShape>(sf::RectangleShape(sf::Vector2f(width,height)));
  shape->setPosition(posx,posy);
  //    std::cout<<posx<<" "<<posy<<" "<<width<<" "<<height<<"   ";
}
Rectangle::Rectangle(const sf::Texture& texture,
		     float posx,float posy,
		     int width,int height,
		     int textwidth,int textheight,
		     int textx,int texty){
  shape=std::make_shared<sf::RectangleShape>(sf::RectangleShape(sf::Vector2f(width,height)));
  shape->setPosition(sf::Vector2f(posx,posy));
  sf::IntRect r1(textx,texty,textwidth,textheight);
  shape->setTexture(&texture);
  shape->setTextureRect(r1);
}
Rectangle::~Rectangle(){}
float Rectangle::x() {
  return shape->getPosition().x;
}
float Rectangle::y() {
  return shape->getPosition().y;
}
float Rectangle::limLeft() {
  return x() /*- shape->getSize().x / 2.f*/;
}
float Rectangle::limRight() {
  std::shared_ptr<sf::RectangleShape> rect=std::dynamic_pointer_cast<sf::RectangleShape>(shape);
  return x() + rect->getSize().x/* / 2.f*/;
}
float Rectangle::limUp() {
  return y() /*- shape->getSize().y / 2.f*/;
}
float Rectangle::limDown() {
  std::shared_ptr<sf::RectangleShape> rect=std::dynamic_pointer_cast<sf::RectangleShape>(shape);
  return y() + rect->getSize().y /* / 2.f*/;
}

