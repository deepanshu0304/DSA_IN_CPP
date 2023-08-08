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
    // you can preset the the size of vector
       // vector <int> v(10);  --> if you write this it mean 10 size vector is created and all are initialized by 0..
       vector <int> v(10,3);  // this mean initialized by 3
        v.push_back(7);
        printvec(v);
        
        v.pop_back();  // will remove the last element of vector
        printvec(v);

         vector<int> v2 = v;
      /*
      now the upper thing you can not do in array ....copying the whole vector
      you can do this in array by using pointer but that is diffrent ...if you change in array2 it will change array also
      but here if you change v2 it will not effect v......
      */ 
        v2.push_back(6);
         printvec(v);
         printvec(v2);

    return 0;
}
/*
now copying the vector is simply one line step with using assignment operator
but its time complexity is not 0(1)....
its actually 0(n)......as all element are being copying one by one
*/