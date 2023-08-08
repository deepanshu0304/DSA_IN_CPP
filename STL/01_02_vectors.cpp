#include<bits/stdc++.h>
using namespace std;
// passing vector to function is also copy which is expensive ....so be careful
void printvec(vector<int> v){
        cout<<"size: "<<v.size()<<endl;
    for(int i =0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    // proof that vector passed is copy 
    v.push_back(2);   // see it's having no effect ....hence copy is passed
}

int main(){
       // you can define the the size of vector
       // vector <int> v(10);  --> if you write this it mean 10 size vector is created and all are initialized by 0..
       vector <int> v(10,3);  // this mean initialized by 3
        v.push_back(7);
        printvec(v);
        
        v.pop_back();  // will remove the last element of vector
        printvec(v);

         vector<int> v2 = v;   // Time complexity is 0(n)
      /*
      Now unlike array we can copy whole vector as shown above
      In array it is possible by using pointers but that is not copy because they will be pointing to same memory address.
      */ 
        v2.push_back(6);
         printvec(v);
         printvec(v2);

    return 0;
}
