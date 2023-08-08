#include<bits/stdc++.h>
using namespace std;

int main(){
    pair<int,string> p ;
    // p = make_pair(2,"abc"); // one way of initialisation

    p = {2,"abc"};   // other way of initialization
    p = {4, "sdf"};
    pair<int , string> p1 =p;

    p1.first = 3; // this will not effect p.first ...as this is same as asigning a to b then you change b will not change a
   
     /*
     we can create a refrence in this also
     */
     pair<int , string> &p2 =p;
     p2.first =3;  // now it will also change the value in p...
    cout<<p.first<<" "<<p.second<<endl;   

    // one use can be to relate two array like there are two array you want same operation in them..
        
    return 0;
}
