#ifndef CIRCLE_HH
#define CIRCLE_HH
#include "mobile2d.hh"
#include <memory>
class Circle:public mobile2d{
  //std::shared_ptr<sf::CircleShape> shape;

public:
  Circle();
  Circle(prologparse*);
  Circle(int,int);
  Circle(prologparse*,int,int);
  float x()override ;
  float y()override ;
  float limLeft()override ;
  float limRight()override;
  float limUp()override ;
  float limDown()override ;
  void moveLeft()override;
  void moveRight()override;
  void moveUp()override;
  void moveDown()override;
  //std::shared_ptr<sf::CircleShape> getMobile(){return shape;}
};

#endif // CIRCLE_HH
