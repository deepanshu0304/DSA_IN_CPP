#include<bits/stdc++.h>
using namespace std;

int main(){
    vector <int> v = {1,2,3,4,5};
    for (int i =0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    /*
    Syntax of declaring a iterators.
    [data_structure_name] :: iterators [any_name] ;
    there are two methods begin and end ...begin point to the first element of data structure 
    and end point to the address which is just after the end of data structure
    */
    vector<int> :: iterator it = v.begin() ; // we declared iterator which is pointing to first element of vector....
    cout<<*it<<endl;
    cout<<*(it+1)<<endl; // below two method are also correct way of writing
    cout<<*(++it)<<endl;
    cout<<*++it<<endl;
    for(it=v.begin(); it !=v.end();it++){   // iterator doesn't make lot of sense in vectors because it is linear data structure so we can access it 
        // using indexes but iterator is imp in case of maps and sets...
        cout<<*it<<endl;
    }
    return 0;
}

/*
Important concept 
suppose there is variable named a.
i.) a=a+1;
ii.) a++;
Here meaning of i.) and ii.) are same they will do same operation
but in case of iterators these two are different things (except vectors)..
if we do it = it+1 ....it will take us to the next address( now for linear structure next address in memory and 
address for next element is same but for non linear data structure they are different so we need to carefully use these things...
we will use it++ which will take us to the next element of tha data structure.

*/
