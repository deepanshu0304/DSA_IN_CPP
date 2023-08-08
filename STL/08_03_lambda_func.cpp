 /*the syntax for lambda function is 
 [](){;}()
 first braclet is as it is 
 second bracket is the variable you are passing in it 
 third bracket is return
 4th one is value yiou are passing
 
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<[](int x){return x+2;}(2);
    auto sum =  [](int x , int y){return x+y;};
    cout<<sum(2,3);
    return 0;
}