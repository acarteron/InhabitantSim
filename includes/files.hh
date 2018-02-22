/**
 * \class Files
 *
 * \brief Read Write files
 *
 * \note nothing to add
 *
 * \author $Author: Adrien Carteron$
 *
 * \version $Revision: 1.0 $
 *
 * \date $Date: 2014/07/11 $
 *
 * Contact: acarteron@openmailbox.org
 *
 * Created on: 2011/04/11
 *
 *
 */
#ifndef FILES_HH
#define FILES_HH

//#include <iostream>
#include <sstream>
#include <fstream>
#include <istream>
#include <cstring>
#include <vector>

class Files{
private:
  std::string fileName; ///< the file name

  std::string ResRead; ///< the line read

  std::ifstream curentFile; ///< the reading stream
  std::ofstream curentFileO; ///< the writing stream
  std::string openingMode; ///< the opening mode

  void define_mode(unsigned int);
  
  /// This method creates the input or output stream
  void create_File();

public:
  /** \brief Void constructor
   * 
   * This only set opening method as in  
   * 
   */
  Files();
  /** \brief One arguement constructor
   * \param opening mode
   * 
   * Set opening mode as in if ague is 0 
   * out else  
   *
   */
  Files(unsigned int);
  /** \brief One arguement constructor
   * \param file name as string
   * 
   * Set opening mode as in
   * set file name calling method setFileName  
   *
   */
  Files(std::string);
  /** \brief Two arguement constructor
   * \param file name as string, opening mode as string
   * 
   * Set opening mode
   * set file name calling method setFileName  
   *
   */
  Files(std::string,std::string);
  /** \brief Destructor
   * 
   * Close the file 
   *
   */
  virtual ~Files();
  /** \brief Method to set file name
   * \param file name as string
   *
   */
  virtual void setFileName(std::string);
  /** \brief Two arguement constructor
   * \param file name as string, opening mode as string
   * 
   * Set opening mode
   * set file name calling method setFileName  
   *
   */
  virtual int openFile();
  virtual int closeFile();
  virtual std::string readFile();
  virtual std::string readLine();
  virtual std::vector<std::string> readLines();

  virtual int writeFile(std::string);

};

#endif
