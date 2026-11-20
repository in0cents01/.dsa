#include <bits/stdc++.h> 
using namespace std ; 
  

int main() {
 
  std::vector <int> data {1,3,4,5,6} ;  // data size   : 5 
  data.at(1)   = 10 ;    // index at 1   = 10   
  std::cout << "Element at index 2 has value : " << data.at(2) << " \n" ;  

  std::cout << "data size : " << data.size()  << "\n " ;  //  output size of data 
  
  try {
    auto moon_phase = [] 
    {
      return std::chrono::system_clock::now().time_since_epoch().count() % 8 ;  

    } ;   
    data.at(data.size() + moon_phase())  = 13 ;  
  } 
  catch(const std::out_of_range& ex)
  {
    std::cout << ex.what() << "\n" ;
  }
  std::cout << "data : " ;
  for (int elem  : data ) {
    std::cout << " " << elem  ;
  } 
  std::cout <<  " \n " ; 
  return  0 ; 
}
