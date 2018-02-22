#ifndef PROLOGPARSE_HH
#define PROLOGPARSE_HH
#include <gprolog.h>
#include <string>
#include <iostream>
#include <tuple>
#include <vector>
#include <typeinfo>

#include <cstddef>

//template<class Value, class ...Values>

class prologparse{

private:
  std::vector<PlTerm> gEvents;
  //unsigned int cpt=0;
  //template<typename Value>
  
  
  // template<typename Value>
  // void unstack(Value element){
  //   if(typeid(element)==typeid(int)){
  //     variadic_types.push_back("int");
  //   }else{
  //     if(typeid(element)==typeid(const char*)){
  // 	variadic_types.push_back("string");
  //     }
  //   }
  //   //std::cout<<element<<" "<<typeid(element).name()<<std::endl;
  // }
  void unstack(int element){
    gEvents.push_back(Mk_Integer(element));
  }
  void unstack(const char* element){
    gEvents.push_back(Mk_String(element));
  }
  void unstack(std::string element){
    gEvents.push_back(Mk_String(const_cast<char*>(element.c_str())));
  }
  void unstack(float element){
    gEvents.push_back(Mk_Float(element));
  }
  template<typename ...Values>
  void unstack(int element,Values... elements){
    gEvents.push_back(Mk_Integer(element));
    unstack(elements...);
  }
  template<typename ...Values>
  void unstack(const char* element,Values... elements){
    gEvents.push_back(Mk_String(element));
    unstack(elements...);
  }
  template<typename ...Values>
  void unstack(std::string element,Values... elements){
    gEvents.push_back(Mk_String(const_cast<char*>(element.c_str())));
    unstack(elements...);
  }
  template<typename ...Values>
  void unstack(float element,Values... elements){
    gEvents.push_back(Mk_Float(element));
    unstack(elements...);
  }
  
public:
  /** \brief Void constructor
   * 
   * add desc 
   * 
   */
  prologparse(){
    std::cout<<"lol"<<std::endl;
    //
     // int stt=Start_Prolog(1, new char*());
     // std::cout<<stt<<std::endl;
     //Try_Execute_Top_Level();
  }
  void resetPl(){
    Pl_Reset_Prolog ();
  }
  int startPl(){
    return Start_Prolog(1, new char*());
  }
  void stopPl(){Stop_Prolog();}
  // /** \brief Destructor
  //  * 
  //  * add desc
  //  *
  //  */
  ~prologparse(){
    //Stop_Prolog();
  }
  // PlTerm to_gEvent(std::string type_, std::string location_, unsigned long begin_, unsigned long end_);

  //bool intersect(int au,)

  int rule(std::string name){
    Pl_Reset_Prolog ();
    PlTerm plt[1];
    
    int func;
    int gRes=-1;
    func = Find_Atom(const_cast<char*>(name.c_str()));
    Pl_Query_Begin(PL_FALSE);
    std::cout<<func<<std::endl;
    gRes = Pl_Query_Call(func, 1, plt);
    Pl_Query_End(PL_KEEP_FOR_PROLOG);
    if(gRes==1){
      std::cout<<"true"<<std::endl;
    }
    gEvents.clear();
    return gRes;
    //std::cout<<gRes << " "<<true<<std::endl;
  }

  template<typename Value,typename... Values> 
  int rule(std::string name,Value val,Values... vals){
    Pl_Reset_Prolog ();
    unstack(val,vals...);
    std::tuple<Value,Values...> tupl(val,vals...);
    //gEvents.push_back(Mk_Variable());
    PlTerm* plt=&gEvents[0];
        std::cout<<gEvents.size()<<std::endl;

    int func;
    int result=-1;
    func = Find_Atom(const_cast<char*>(name.c_str()));
    std::cout<<func<<" "<<Rd_Float(plt[0])<<std::endl;
    //plt[0]=1;plt[1]=1;plt[2]=1;plt[3]=1;plt[4]=1;plt[5]=1;plt[6]=1;
    
    Pl_Query_Begin(PL_FALSE);
    result=Pl_Query_Call(func, gEvents.size(), plt);
    Pl_Query_End(PL_KEEP_FOR_PROLOG);
    if(result==1){
      std::cout<<"true"<<std::endl;
    }else{
      if(result==0){
    	std::cout<<"false"<<std::endl;
      }
    }
    gEvents.clear();
    return result;
  }

  template<typename Value>
  void process_one_type(){
    std::cout<<typeid(Value).name()<<" ";
  }
  
  template <typename... Values>
  void unpack(){
    int _[]={0,(process_one_type<Values>(),0)...};
    (void)_;
    std::cout<<std::endl;
  }
  
};

#endif // PROLOGPARSE_HH
