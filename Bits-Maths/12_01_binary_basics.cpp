#include <bits/stdc++.h>
// All the logic operator are of 0(1)
using namespace std;
/*
An integer can store maximum of 32 bit number .....and max 32 bit number is 4294967295
but when you declare int of max type it does not store this*/
int main()
{
    cout << INT_MAX << endl; // it will give 2147483647
    // now we will store 32 bit number...
    // int a=(1<<32)-1;// this will give us warning as 1<<32 is 33 bit number later we are doing -1 but intialy it is overflowing
    // int a  = (1LL<<32)-1; // again its not giving correct ans...data is overflowing
    //  it is not able to store 32 bit number ok ...lets find out how much this can store

    int a = (1LL << 31) - 1; // this is working so we can store 31 bit number in array because oe bit is reserved for sign weather the number is positive or negative

    cout << a << endl;
    // so if we declare unsigned int this problem should be solved....
    unsigned int b = (1LL << 32) - 1;

    cout << b << endl; // it is working

    return 0;
}