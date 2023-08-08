// it can store duplicate ...
#include<bits/stdc++.h>
using namespace std;
int main(){
  multiset<string> s;
  s.insert("abc");
  s.insert("avdvbc");
  s.insert("abnmkc");
  s.insert("abc")   ;
  s.insert("abghyc");
  s.insert("avkfbc");
    for(auto value:s){
      cout<<value<<endl;
  }

  // Some interesting points....
  // when you use find function it will give iterator of first one (in case of repeating )

  /* Now we know erase function can be used in two way one with iterator second with key
  if you use erase function in multiset using iterator it will delete only that particular element
  and if you use it using key it will delete all element of that key*/




  //   auto it = s.find("abc");
  //   s.erase(it);

  // for(auto value:s){
  //     cout<<value<<endl;
  // }




  s.erase("abc");

    for(auto value:s){
      cout<<value<<endl;
  }
  return 0;
}