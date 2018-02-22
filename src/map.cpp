#include "map.hh"

int map::find_block(std::vector<block> blocks,int x,int y){
  bool found=false;
  int indice=-1;
  for(size_t i(0);i<blocks.size()&&!found;++i)
    if(blocks[i].dots[0].x==x&&blocks[i].dots[0].y==y){
      found=true;
      indice=i;
    }
  return indice;
}
void map::defineMatrice(){
  matrice.data=image.data;
  matrice.cols=image.cols;
  matrice.rows=image.rows;
}

int map::loadMapFromTxt(std::string path){
  Files file(path);
  blocks.clear();
  std::string fileContent=file.readFile();
  file.closeFile();
  std::vector<std::string> contents=Utils::splitString(fileContent,'\n');
  for(size_t i(0);i<contents.size();++i){
    if(contents[i].compare("")!=0){
      std::vector<std::string> dots=Utils::splitString(contents[i]," ");
      dot dt1,dt2;
      dt1.x=Utils::stringTo<int>(dots[0]);dt1.y=Utils::stringTo<int>(dots[1]);
      dt2.x=Utils::stringTo<int>(dots[2]);dt2.y=Utils::stringTo<int>(dots[3]);
      block blk;
      blk.dots.push_back(dt1);
      blk.dots.push_back(dt2);
      blocks.push_back(blk);
    }
  }
  return 0;
}
  
int map::loadMapFromImage(std::string path){
  image = cv::imread(path,cv::IMREAD_GRAYSCALE );
  if(path.empty()){
    std::cerr << "Cannot read image file: " << "" << std::endl;
    return -1;
  }
  defineMatrice();
  return 0;
}
void map::defineBlocks(){
  unsigned int rows = image.rows;
  unsigned int cols = image.cols;
  bool current=false;
  std::vector<block> blocks2;
  for(size_t y(0); y<rows; ++y){
    dot dt;
    for(size_t x(0); x<cols; ++x){
      if(image.data[x+y*cols]==0){
	if(!current){
	  dt.x=x;dt.y=y;
	  block blk;
	  blk.dots.push_back(dt);
	  blocks2.push_back(blk);
	  current=true;
	}
      }else{
	if(current){
	  dt.x=x-1;dt.y=y;
	  blocks2.back().dots.push_back(dt);
	  current=false;
	}
      }
    }
  }
  for(size_t i(1);i<blocks2.size();++i){
    bool stopJ=false;
    for(int j(i-1);j>=0&&!stopJ;--j){
      if(blocks2[i].dots[0].x==blocks2[j].dots[0].x&&
	 blocks2[i].dots[1].x==blocks2[j].dots[1].x){
	if(image.data[blocks2[i].dots[0].x+(blocks2[i].dots[0].y-1)*cols]!=0||
	   image.data[(blocks2[i].dots[0].x+blocks2[i].dots[1].x)/2
		      +(blocks2[i].dots[0].y-1)*cols]!=0||
	   image.data[blocks2[j].dots[0].x+(blocks2[j].dots[1].y+1)*cols]!=0){
	  stopJ=true;
	}else{
	  blocks2[i].dots[0].y=blocks2[j].dots[0].y;
	  blocks2[i].treat=true;
	  blocks2[j].treat=false;
	}
      }
    }
  }
  for(size_t i(0);i<blocks2.size();++i){
    if(blocks2[i].treat){
      blocks.push_back(blocks2[i]);
    }
  }
  std::cout<<blocks.size()<<std::endl;
}
std::vector<block> map::getBlocks(){
  return blocks;
}
mat map::getMat(){
  return matrice;
}
