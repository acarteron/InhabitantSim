#include <iostream>
#include <SFML/Graphics.hpp>
#include "path.hh"
#include "parameters.hh"
//#include "controle.hh"
#include "Circle.hh"

#include "Rectangle.hh"
#include "map.hh"
#include "prologparse.hpp"
#include <vector>
#include <cmath>


int main(int argc, char** argv){
  if(argc>1){
    for(int i(1);i<argc;++i){
      std::cout<<argv[i]<<std::endl;
    }
  }else{
    std::cout<<"no arguments"<<std::endl;
  }
  std::cout<<"Bouyah "<<true <<std::endl;


  prologparse *plp=new prologparse();
  
  //cv::Mat model;
 
  sf::Texture texture22;
  if (!texture22.loadFromFile(texturePath+"beton/22.jpg")){
    // erreur...
  }
  std::vector<std::shared_ptr<still2d>> rectangles;
  map mp;
  // mp.loadMapFromImage("media/gfx/map.png");
  // mp.defineBlocks();
  mp.loadMapFromTxt("media/maps/map1.txt");
  //mp.defineBlocks();
  std::vector<block> blocks=mp.getBlocks();

  for(size_t i(0);i<blocks.size();++i){
    rectangles.push_back(std::make_shared<Rectangle>(Rectangle(blocks[i].dots[0].x,
							       blocks[i].dots[0].y,
							       blocks[i].dots[1].x-blocks[i].dots[0].x+1,
							       blocks[i].dots[1].y-blocks[i].dots[0].y+1)));
  }

  
  // création de la fenêtre
  sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "My window");
  window.setFramerateLimit(240);
  sf::Texture texture;
  if (!texture.loadFromFile(texturePath+"image.png")){
    // erreur...
  }
  

  //std::vector<Rectangle> vStill=build_still(texture22,1000,700,15,15);
  texture.setSmooth(true);

  Circle circle(plp);//std::make_shared<prologparse>(*plparse));
  plp->startPl();
  circle.setEnvironment(rectangles);
  circle.getMobile()->setTexture(&texture);
  Circle circle2(plp,1,1);
  circle2.setEnvironment(rectangles);
  //circle.getMobile()->setTextureRect(sf::IntRect(10, 10, 100, 100));
  //controle contr;
  //mobile2d& mob=circle;
  // on fait tourner le programme tant que la fenêtre n'a pas été fermée
  while (window.isOpen())
    {
      // on traite tous les évènements de la fenêtre qui ont été générés depuis la dernière itération de la boucle
      sf::Event event;
      while (window.pollEvent(event))
	{
	  // fermeture de la fenêtre lorsque l'utilisateur le souhaite
	  if (event.type == sf::Event::Closed)
	    window.close();
	}

      // effacement de la fenêtre en noir
      window.clear(sf::Color::Black);

      
      //contr.controleMovable2d(circle);
      //plp->rule("inter");
      circle.update();
      circle2.update();
      // c'est ici qu'on dessine tout
      // window.draw(...);
      for(size_t i(0);i<rectangles.size();++i){
	window.draw(*(rectangles[i]->getStill()));
      }
      //window.draw(*(stl.getStill()));
      
      window.draw(*(circle.getMobile()));	
      window.draw(*(circle2.getMobile()));

      // fin de la frame courante, affichage de tout ce qu'on a dessiné
      window.display();
    }

  Stop_Prolog();
  return 0;
  

}

/** \mainpage : 
 * \author lildurden
 * \version : 0.0 $
 * \date : mer. févr. 14 16:21:43 CET 2018 $
 * \section intro_sec Introduction
 * Contact: acarteron@openmailbox.org
 * Created on: mer. févr. 14 16:21:43 CET 2018
 *
 * \section install_sec Installation
 *
 * This is f***** easy
 *
 * \subsection step1 Step 1 : Compile
 *
 *  Run this command to the project root
 *  <br/>
 *  <code>make</code>
 *
 * \subsection step2 Step 2 : Launch
 *
 *  Compiled program can be found in the subfolder <code>./bin</code>, it is called <code></code>.
 * 
 *  \subsection step3 Step 3 : Otherwise
 *  
 *  You can read the file <code>README.RTFM</code> if it exists
 */

