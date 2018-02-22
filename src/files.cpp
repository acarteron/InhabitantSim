#include "files.hh"
#include <iostream>

Files::Files(){
  openingMode="in";
}

// Ouverture en lecture 
Files::Files(unsigned int mode_){
  define_mode(mode_);
  //create_File();
}

// Ouverture en lecture 
Files::Files(std::string file){
  openingMode="in";
  setFileName(file);
  //create_File();
}
Files::Files(std::string file,std::string mode){
  //fileName=file;
  openingMode=mode;
  setFileName(file);
  //create_File();
}
Files::~Files(){
  closeFile();
}
void Files::setFileName(std::string file){
  fileName=file;
  create_File();
}

void Files::define_mode(unsigned int mode_){
  if(mode_==0){
    openingMode="in";
  }else{
    openingMode="out";
  }
}

void Files::create_File(){
  if(openingMode=="out"){
    curentFileO.open(fileName.c_str(),std::fstream::out| std::ofstream::app);
  }
  else{
    curentFile.open(fileName.c_str(),std::fstream::in);
  }
}
int Files::openFile(){
  if(openingMode=="out"){
    return curentFileO.is_open();
  }
  else{
    return curentFile.is_open();
  }
}
int Files::closeFile(){
  if(openingMode=="out")
    curentFileO.close();
  else
    curentFile.close();
 return 0;
}
std::string Files::readFile(){
  std::stringstream sstr;
  sstr << curentFile.rdbuf();
  return sstr.str();
}
int Files::writeFile(std::string message){
  curentFileO << message;
  return -1;
}
std::string Files::readLine(){
  std::string line="";
  getline (curentFile,line);
  if(curentFile.eof())
    line="[EOF REACHED]";
  return line;
}

std::vector<std::string> Files::readLines(){
  std::string line="";
  std::vector<std::string> lines;
  while(!curentFile.eof()){
    getline (curentFile,line);
    if(line.compare("")!=0)
      lines.push_back(line);
  }
  // if(curentFile.eof())
  //   line="NONEEOFLOL";
  return lines;
}
