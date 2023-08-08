#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, string> m;
    m[1] = "asd";
    m[2] = "weq";
    m[5] = "zcz";
    m[3] = "def";
    // erase can take two type of input...either key or iterator
    m.erase(3); // time complexity is 0(log(n))....

    auto it = m.find(5);
    if (it != m.end())
    {
        m.erase(it);
    }
    /*use the upper thing carefully .... if you give the non existing key to find... it
    will return m.end and when you try to erase the m.end it will give segmentation fault
    becoz m.end is just representation .....nothing exist there....
    so use of if statement will be handy */

    for (auto value : m)
    {
        cout << value.first << " " << value.second << endl;
    }
}
// clear function is used to clear the full container
// if u used m.clear ...it will clear the full map and size of map will become zero