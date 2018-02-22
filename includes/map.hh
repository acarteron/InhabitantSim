#ifndef MAP_HH
#define MAP_HH

#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include "still2d.hh"
#include "Tools.hpp"
#include "files.hh"
struct dot{
  int x;
  int y;
};
struct block{
  std::vector<dot> dots;
  bool treat=false;
};
struct mat{
  unsigned char*data;
  unsigned int cols;
  unsigned int rows;
};
class map{
private:
  cv::Mat image;
  mat matrice;
  std::vector<block> blocks;
  int find_block(std::vector<block> blocks,int x,int y);
  void defineMatrice();
public:
  int loadMapFromTxt(std::string path);
  int loadMapFromImage(std::string path);
  void defineBlocks();
  std::vector<block> getBlocks();
  mat getMat();
};


#endif // MAP_HH
