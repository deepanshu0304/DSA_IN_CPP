#include<bits/stdc++.h>
using namespace std;

int main(){
    pair<int,string> p ;
    // p = make_pair(2,"abc"); // one way of initialisation

    p = {2,"abc"};   // other way of initialization
    p = {4, "sdf"};
    // pair<int , string> p1 =p;



   // p1.first = 3; // this will not effect p.first ...as this is same as asigning a to b then you change b will not change a
   
   
    /*
    but again we can create a refrence in this also*/
     pair<int , string> &p1 =p;
     p1.first =3;  // now it will also change the value in p...
    cout<<p.first<<" "<<p.second<<endl;   

    // one use can be to relate two array like there are two array you want same operation in them..
    
    int a[] = {1,2,3};
    int b[] = {2,3,4};
    
    // you can declare like this 
    pair<int , int > p_array[3];
    p_array[0] = {1,2}  ;
    p_array[1] = {2,3}  ;
    p_array[2] = {3,4}  ;
    for(int i =0;i<3;i++){
        cout<<p_array[i].first<<" "<<p_array[i].second<<endl;
    } 
    //now suppose you want to swap the arry so no need to perform the func twice ...
    swap(p_array[0],p_array[2]);
    for(int i =0;i<3;i++){
        cout<<p_array[i].first<<" "<<p_array[i].second<<endl;
    } 
    
    return 0;
}