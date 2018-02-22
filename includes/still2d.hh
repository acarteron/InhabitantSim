#ifndef STILL2D_HH
#define STILL2D_HH
#include <SFML/Graphics.hpp>
#include <memory>
class still2d{
protected:
  std::shared_ptr<sf::Shape> shape;
public:
  //still2d(){};
  // still2d(const still2d& still){
  //   shape=still.shape;
  // }
  virtual ~still2d();
  virtual float limLeft();
  virtual float limRight();
  virtual float limUp();
  virtual float limDown();
  virtual float x();
  virtual float y();
  virtual std::shared_ptr<sf::Shape> getStill();
};

#endif // STILL2D_HH
