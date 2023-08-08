/*
lower bound return either the same value if present or it will reruen vallue greater than that
and upper bound always return the bigger value than that*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);

    // because lower bound and upper bound only work in case of sorrted conatianer
     int *p = lower_bound(a,a+n,7);  // it take from where to where+1 we need to find and whose we need to find..
     if(p== a+n) cout<<"NOT FOUND"<<endl;
     else cout<<*p;

    //  now suppose if lower bound not exist then it will return the adrress pointing next to last value  so to prevent that you can put if statement
    return 0;
}
// time complexity for both lower bound and upper bound is log(n)...where n is size of array

/*
when you use upper bound and lower bound in sets and maps 
   lower bound (s.begin() , s.end() , n)..it will take 0(n) complexity 
   in order to do it in log(n) complexity use like this
   s.lower_bound(n)....here  time complexity is log(n)
   same thing in  map..
   in map lower bound and upper bound works for only key...
   This is for all type of containeer
   if multiple element of same type are present then it will return the address of first element...
   */


  /*
  for vector and array  the internal implementation is binary search and for sets and maps 
   the internal implementation is trees.....*/