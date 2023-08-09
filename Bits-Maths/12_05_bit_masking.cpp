#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*
    Bitmasking is converting a problem into binary to make it easy or to reduce time complexity
    specialy used if you need to find smthng common or any other comparison between two things(array,string etc)
    it has limitation...only work  if comparison is between things having their length less than 64 you will understand why....*/

    // Let's  understand it by a que ...

    /*
    Consider this problem: There are N≤5000 workers. Each worker is available during some days of this month
     (which has 30 days). For each worker, you are given a set of numbers, each from interval [1,30], representing
      his/her availability. You need to assign an important project to two workers
      but they will be able to work on the project only when they are both available.
       Find two workers that are best for the job — maximize the number of days when both these workers are available.
    */

    /*
    if you have done it using simple approach ..storing in set or anything and then fiinding intersection
    then the time complexity will be 0(30) for one intersection(by two pointer approach) and for every pair
    0(N^2*30)...but using bitmasking we did that intersection part in 0(1) complexity..reducing
    final complexity to 0(N^2)..faster then previous    */
    int workers;
    cin >> workers;
    vector<int> v(workers, 0);
    for (int i = 0; i < workers; i++)
    {
        int j;
        cin >> j;
        int mask = 0;
        for (int k = 1; k <= j; k++)
        {
            int day;
            cin >> day;
            mask = (mask | (1 << day));
        }
        v[i] = mask;
    }
    int max_days = 0;
    for (int i = 0; i < workers; i++)
    {
        for (int j = i + 1; j < workers; j++)
        {
            int k = v[i] & v[j];
            int common_days = __builtin_popcount(k); // this functiion take approx 0(1) time
            max_days = max(max_days, common_days);
        }
    }
    cout << max_days << endl;
    return 0;
}
/*During revision time try to modify the code and print the workers which you selected*/