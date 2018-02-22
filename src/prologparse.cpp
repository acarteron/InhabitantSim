#include "prologparse.hh"

// prologparse::prologparse(){
// }
// prologparse::~prologparse(){
// }

// PlTerm prologparse::to_gEvent(std::string type_, std::string location_, unsigned long begin_, unsigned long end_){
//   PlTerm gPeriod[2];  
//   PlTerm event[3];
//   gPeriod[0]=Mk_Integer(begin_);
//   gPeriod[1]=Mk_Integer(end_);

//   event[0]=Mk_String(const_cast<char*>(type_.c_str()));
//   event[1]=Mk_String(const_cast<char*>(location_.c_str()));
//   event[2]=Mk_Proper_List(2,gPeriod);

//   return Mk_Proper_List(3,event);
// }

// void prologparse::rule_(std::string name){
//   std::cout<<"begin rule "<<name<<std::endl; 
//   int func;
//   PlTerm gEvents[2];
//   int gRes=-1;
//   size_t size_res=0;

//   PlTerm * gResult;
//   PlTerm * gRole;
//   PlTerm * gPeriod;
//   gRole=new PlTerm[3];
//   gPeriod=new PlTerm[2];

//   gEvents[0] ;//= to_gEvent();
//   gEvents[1] = Mk_Variable();
  
//   func = Find_Atom(const_cast<char*>(name.c_str()));
//   Pl_Query_Begin(PL_FALSE);
//   gRes = Pl_Query_Call(func, 2, gEvents);
//   Pl_Query_End(PL_KEEP_FOR_PROLOG);

//   // if(gRes==1){
//   //   std::vector<abstract::RoleEvent> fails;
//   //   size_res=Pl_List_Length(gEvents[1]);
//   //   gResult=new PlTerm[size_res];
//   //   Rd_Proper_List(gEvents[1],gResult);
//   //   for(size_t i(0);i<size_res;++i){
//   // 	Rd_Proper_List(gResult[i],gRole);
//   // 	Rd_Proper_List(gRole[2],gPeriod);
//   // 	abstract::RoleEvent afail(Rd_Integer(gPeriod[0]),Rd_Integer(gPeriod[1]),Rd_String(gRole[0]),Rd_String(gRole[1]));
//   // 	fails.push_back(afail);
//   //   }
//   //   rules_fails.emplace_back(std::make_pair(name,fails));
//   // }
// }
