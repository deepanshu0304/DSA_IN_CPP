#include <bits/stdc++.h>
/* 
Maps are of many type
--> First of all simple map.......
it will arrange itself in order ..no matter in which order you insert values....and it is pair of key and value....
Internally it follow Red Black Trees algo and we don't need to go deep into it
*/
using namespace std;

int main()
{
    map<int, string> m;
    m[1] = "abc";
    m[5] = "defsdewf";
    // m[5] = "asasa"; --> this will update the value of m[5] only...
    m[2] = "def";
    m.insert({4, "deepu"});  // diffrent way of inititalizing maps....
    // m.insert(make_pair(4, "deepu")); ---> Diffrent way of writing upper line....
    /*
     map<int,string> :: iterator it;
     for(it = m.begin() ;it != m.end() ; it++){
         cout<<(*it).first<<" "<<(*it).second<<endl;
     }


     upper thing is noob
      */

    // Pro method
   /*
    for (auto value : m)
    {
        cout << value.first << " " << value.second << endl;
    }
    */

    for (auto [key,value] : m)
    {
        cout << key << " " << value << endl;
    }

   // ultra pro max
    /*
    in upper section we accessed the value of maps....and it is done by using iterator indirectly
    and time complexity for accessing it by iterator is 0(1)...also it++ is of 0(1) complexity
    so you traverse whole map in 0(1) complexity
    But when you try to access a specific value in map(how that u will learn later)
    it will take log(n) complexity....
    */

    return 0;
}




// Time complexity of inserting a new element in map is  is 0(log n) ... where n is current size of maps 
/* Even if you declare map like m[6]...becoz it automatically take value as empty string is case 
of string and will take 0 in case of int or any other number datatype....empty vector in case of vector
.....it will take complexity ....so be carefull....*/









/*
Not always time complexity of inserting new element in map is log(n)
it depend on key .....as when you enter new element it will compare with all
other existing key and then get placed at it's place
suppose u created a map with keytype string
then the time complexity will be 
s.size()*log(n)....
inserting of small string does not effect much ..but insertion of big string have 
considerable diffrence....and this is the case for this map
for unordered map things are diffrent...
*/