 

#include <iostream> 
#include <string> 

using namespace std ; 
int main () {
 

  std::string str1  = "Hello" ; 
  std::string str2  = "World";
  std::string  str3   = str1 + " " + str2; 

  std::cout  << str3 << " \n" ;  
  std::string::size_type pos  = str3.find(" ") ;  
  str1 = str3.substr(pos+1) ; 
  str2 = str3.substr(0,pos) ;
  std::cout << str1  << " " << str2 << "\n" ; 



   // access 

  std::cout << str1[0] << "\n" ;  
  str1[0]  = 'w' ; 
  std::cout << str1  << "\n" ; 
  return  0; 
}
