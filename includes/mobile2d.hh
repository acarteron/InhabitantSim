#ifndef MOBILE2D_HH
#define MOBILE2D_HH
#include "map.hh"
#include "controle.hh"
#include "parameters.hh"
#include "still2d.hh"
#include "prologparse.hpp"
//#include "Rectangle.hh"

// template <class T1, class T2>
// bool isIntersecting(T1& mA, T2& mB) noexcept
// {
//     return mA.limRight() >= mB.limLeft() && mA.limLeft() <= mB.limRight() &&
//            mA.limDown() >= mB.limUp() && mA.limUp() <= mB.limDown();
// }

template <class T1, class T2>
bool isIntersectLeft(prologparse plparse,
		     T1& mA,
		     T2& mB) noexcept{
 return plparse.rule("intersectLeft",
		mA.limLeft(),
		mA.limDown(),
		mA.limUp(),
		mB.limLeft(),
		mB.limRight(),
		mB.limDown(),
		mB.limUp());
  // return mA.limLeft() >= mB.limLeft()
  //   && mA.limLeft() <= mB.limRight()
  //   && mA.limDown() > mB.limUp()
  //   && mA.limUp() < mB.limDown();
}
template <class T1, class T2>
bool isIntersectRight(prologparse plparse, T1& mA, T2& mB) noexcept{
  return plparse.rule("intersectRight",
		mA.limRight(),
		mA.limDown(),
		mA.limUp(),
		mB.limLeft(),
		mB.limRight(),
		mB.limDown(),
		mB.limUp());
  // return mA.limRight() >= mB.limLeft()
  //   && mA.limRight() <= mB.limRight()
  //   && mA.limDown() > mB.limUp()
  //   && mA.limUp() < mB.limDown();
}
template <class T1, class T2>
bool isIntersectUp(prologparse plparse, T1& mA, T2& mB) noexcept{
  return plparse.rule("intersectUp",
		mA.limLeft(),
		mA.limRight(),
		mA.limUp(),
		mB.limLeft(),
		mB.limRight(),
		mB.limDown(),
		mB.limUp());
  // return mA.limRight() > mB.limLeft()
  //   && mA.limLeft() < mB.limRight()
  //   && mA.limUp() >= mB.limUp()
  //   && mA.limUp() <= mB.limDown();
}
template <class T1, class T2>
bool isIntersectDown(prologparse plparse, T1& mA, T2& mB) noexcept{
  return plparse.rule("intersectDown",
		mA.limLeft(),
		mA.limRight(),
		mA.limDown(),
		mB.limLeft(),
		mB.limRight(),
		mB.limDown(),
		mB.limUp());
  // return mA.limRight() > mB.limLeft()
  //   && mA.limLeft() < mB.limRight()
  //   && mA.limDown() >= mB.limUp()
  //   && mA.limDown() <= mB.limDown();
}

class mobile2d{
protected:
  std::vector<std::shared_ptr<still2d>> environment;
  std::shared_ptr<sf::Shape> shape;
  prologparse * plparse;
  //prologparse plparse2;

public:
  mobile2d();
  mobile2d(prologparse* plparse_);
  virtual ~mobile2d();
  virtual float x()=0;
  virtual float y()=0;
  virtual float limLeft()=0; 
  virtual float limRight()=0;
  virtual float limUp()=0; 
  virtual float limDown()=0;
  virtual void moveLeft()=0;
  virtual void moveRight()=0;
  virtual void moveUp()=0;
  virtual void moveDown()=0;
  void setEnvironment(std::vector<std::shared_ptr<still2d>>& blks) ;
  void motion();
  void update();
  std::shared_ptr<sf::Shape> getMobile();

};

#endif // MOBILE2D_HH
