#include "mobile2d.hh"
#include "plparse.hh"
mobile2d::mobile2d(){
  
  //plparse=new prologparse();
}
mobile2d::mobile2d(prologparse * plparse_){
  plparse=plparse_;
  //std::cout<<"sda"<<std::endl;
  //    plparse_->resetPl();

  //plparse_->rule("inter");
  //plparse_->stopPl();
}
mobile2d::~mobile2d(){
}
void mobile2d::setEnvironment(std::vector<std::shared_ptr<still2d>>& blks){
  environment=blks;
}
void mobile2d::update(){
  motion();
}
void mobile2d::motion(){
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && limLeft() > 0){
    bool intersect=false;
    for(size_t i(0);i<environment.size()&&!intersect;++i){
      if(isIntersectLeft(*plparse,*this,*environment[i])){
  	intersect=true;
      }
    }
    if(!intersect)
      moveLeft();
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&& limRight()<windowWidth){
    bool intersect=false;
    for(size_t i(0);i<environment.size()&&!intersect;++i){
      if(isIntersectRight(*plparse,*this,*environment[i])){
  	intersect=true;
      }
    }
    if(!intersect)
      moveRight();
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&& limUp() > 0){
    bool intersect=false;
    for(size_t i(0);i<environment.size()&&!intersect;++i){
      if(isIntersectUp(*plparse,*this,*environment[i])){
  	intersect=true;
      }
    }
    if(!intersect)
      moveUp();
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && limDown() < windowHeight){
    bool intersect=false;
    for(size_t i(0);i<environment.size()&&!intersect;++i){
      if(isIntersectDown(*plparse,*this,*environment[i])){
  	intersect=true;
      }
    }
    if(!intersect)
      moveDown();
  }
}
std::shared_ptr<sf::Shape> mobile2d::getMobile(){
  return shape;
}
