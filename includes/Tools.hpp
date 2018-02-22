/**
 * \class Utils
 *
 * \brief Contains some useful methods and tricks
 *
 * \note Accept somme things to be add in
 *
 * \author $Author: Adrien Carteron$
 *
 * \version $Revision: 0.5 $
 *
 * \date $Date: 2014/07/11 $
 *
 * Contact: acarteron@openmailbox.org
 *
 * Created on: 2012/11/12
 *
 *
 */

#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <sstream>
#include <cmath>
#include <vector>
#include <algorithm>

class Utils{
private:
public:
  /** \brief A method to get current date and time as string.
   * \return Current date and time as string
   */
  static std::string getTime(){
    time_t now = time (NULL);
    /* la convertir en heure locale */
    struct tm tm_now = *localtime (&now);
    /* Creer une chaine JJ/MM/AAAA HH:MM:SS */
    char s_now[sizeof "AAAA-MM-JJ HH:MM:SS.000"];
    strftime (s_now, sizeof s_now, "%Y-%m-%d %H:%M:%S.000", &tm_now);
    return toString(s_now);
  }
  static std::string getDay(){
    time_t now = time (NULL);
    /* la convertir en heure locale */
    struct tm tm_now = *localtime (&now);
    /* Creer une chaine JJ/MM/AAAA HH:MM:SS */
    char s_now[sizeof "AAAA-MM-JJ"];
    strftime (s_now, sizeof s_now, "%Y-%m-%d", &tm_now);
    return toString(s_now);
  }
    /** \brief A method to convert any type of input in string
   * \param any type of data
   * \return data given as string
   * 
   * HowTo:
   * int truc=42;
   * string machin=Utils::toString<int>(truc);
   *
   */
  template <typename type>
  static std::string toString(type var){
    std::ostringstream ss;
    ss << var;
    return ss.str();
  }
  /** \brief A method to convert a string as any type of data
   * \param a data as string
   * \return data given as any type
   *
   * HowTo:
   * string machin="42";
   * int truc=Utils::stringTo<int>(machin);
   * 
   */
  template <class type>
  static type stringTo(std::string val){
    type ret;//=NULL;
    std::istringstream istr(val);    
    istr >> ret;
    return ret;
  }
  template <class type>
  static int find_in_vector_str(std::vector<type> vect,
				type val){
    bool found=false;
    int indic=-1;
    for(size_t i(0);i<vect.size()&&!found;++i){
      if(vect[i]==val){
	indic=i;
	found=true;
      }
    }
    return indic;
  }
  static int find_in_vector_str(std::vector<std::string> vect,
				std::string val){
    bool found=false;
    int indic=-1;
    for(size_t i(0);i<vect.size()&&!found;++i){
      if(vect[i].compare(val)==0){
	indic=i;
	found=true;
      }
    }
    return indic;
  }
  static void display_progress(std::string message_,
			       size_t begin_,
			       size_t end_ ){
    std::string display="echo -en \"\r";
    display+=message_;
    display+=": ";
    display+=Utils::toString<size_t>(begin_);
    display+="/";
    display+=Utils::toString<size_t>(end_);
    display+="\"";
    std::system(display.c_str());
  }
  static double GetFloatPrecision(double value, double precision){
    return (floor((value * pow(10, precision) + 0.5)) / pow(10, precision)); 
  }
  static std::vector<std::string> splitString(std::string str_,std::string delimiter){
    size_t pos = 0;
    std::vector<std::string> token;//="[";
    while ((pos = str_.find(delimiter)) != std::string::npos) {
      token.push_back(str_.substr(0, pos));
      str_.erase(0, pos + delimiter.length());
    }
    token.push_back(str_);
    return token;
  }
  static std::vector<std::string> splitString(std::string str_,char delimiter){
    size_t pos = 0;
    std::vector<std::string> token;//="[";
    while ((pos = str_.find(delimiter)) != std::string::npos) {
      token.push_back(str_.substr(0, pos));
      str_.erase(0, pos + 1);
    }
    token.push_back(str_);
    return token;
  }
  static std::string trim(std::string& s){
    s.erase(std::remove_if(begin(s), end(s),
			   [l = std::locale{}](auto ch) { return std::isspace(ch, l); }
			   ), end(s));
    return s;
  }
};

#endif //UTILS_HPP
