/*
There are three difrrences between simple map and unordered map 
1)   inbuilt implementation  ---> uses hash table
2)    time complexity   --->     time complexity is less 0(1) for both inserting and accessing
so it is preffered to use unordered .... in order to decrease time complexity
3)    valid keys datatype ---> all general datatype and strings...
we can not use complex conta iners as key in unordered map becoz of inbuilt implementation 
as there is no such hash function defined for these complex container 
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<int,string> m;
    m[1]="asdf";
    m[2]="ijk";
    m[5]="qwert";
    m[3] = "cvbn";
    for(auto value : m){
        cout<<value.first<<" "<<value.second<<endl;
    }
    return 0;
}



//Multi map we will discus later.....as they are not very much used in cp....
// multimap is ordered map with only diffrence that we can create one to many mapping ...means we can store
// two values crrosponding to one key.....











