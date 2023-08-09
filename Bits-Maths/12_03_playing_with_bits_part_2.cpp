#include <bits/stdc++.h>
using namespace std;
void printbinary(int n){
    for(int i=10;i>=0;i--){
        cout<<((n>>i)&1);
    }
    cout<<endl;
}
// Divide and modulo are slow operators as compare to bit manipulaton...
int main()
{
    // To check if the nmber is odd or even 
    int a;
    cin >> a;
    if (a & 1)
    {
        cout << "odd" << endl;
    }
    else
        cout << "Even" << endl;

        // To divide or multiply a number with 2 or power of 2...
        cout<<(a>>1)<<endl;
        cout<<(a<<1)<<endl;

        for(char i ='A';i<='E';i++){
            cout<<i<<endl;
            printbinary(int(i));

        }
        for(char i ='a';i<='e';i++){
            cout<<i<<endl;
            printbinary(int(i));

        }

        // converting uppercase to lower case

        char i = 'C';
        char j =  ((int)i|(1<<5));
        cout<<j<<endl;
        

        // converting lower case to upper case
        char b = 'b';
        char c=((int)b)&(~(1<<5));
        cout<<c<<endl;

        // Having some fun;
        cout<<(char)(1<<5)<<endl;  // it is printing space as 32 is ascii value of space..
        

        cout<<(char)(i+(1<<5))<<endl;
        cout<<(char)('Z'|' ')<<endl;
        cout<<(char)('b'-(1<<5))<<endl;
        cout<<(char)('m'&(~(' ')))<<endl;
        cout<<(char)('m'&('_'))<<endl;

        // how to unset all lsb bit upto given index
        // clear all bit of n upto 4th bit...
        int n;
        cin>>n;
        printbinary(n);
        int p = n&(~((1<<(4+1))-1));
        printbinary(p);
        
        // how to unset all msb bit upto given index....do by own..\



        // to check if the number is power of 2...

        int x;
        cin>>x;
        if(x&(x-1)){
            cout<<"not power of 2"<<endl;
        }
        else 
            cout<<"power of 2"<<endl;

    return 0;
}