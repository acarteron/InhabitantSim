#ifndef RECTANGLE_HH
#define RECTANGLE_HH

#include "still2d.hh"
#include <iostream>
class Rectangle : public still2d{
private:
  //std::shared_ptr<sf::RectangleShape> shape;//(sf::Vector2f(120, 50));
public:
  //Rectangle(){}
  Rectangle(float posx=0,float posy=0,
	    int width=20,int height=20);
  Rectangle(const sf::Texture& texture,
	    float posx=0,float posy=0,
	    int width=20,int height=20,
	    int textwidth=20,int textheight=20,
	    int textx=0,int texty=0);
  ~Rectangle();
  float x()override ;
  float y()override ;
  float limLeft()override ;
  float limRight()override ;
  float limUp()override ;
  float limDown()override ;
};

#endif // RECTANGLE_HH
