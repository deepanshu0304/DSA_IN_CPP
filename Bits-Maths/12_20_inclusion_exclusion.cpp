#include <bits/stdc++.h>
using namespace std;
/*
?Given T test case in each test case there are N name from which you have to select
?Three names such that they have atleast one vowel in common
*/

/*
There are 5 vowels a,e,i,o,u....we will make each and every pair of vowel
and will count the corrosponding names...i.e the names which contain the vowels in particular pair
for ex there will be pairs like a,e,i,o,u,ae,ai,ao,au,aeu...etc etc
suppose the name are given like this selena deepu  here will say ea pair =1 eu pair =1
*/
bool isVowel(char a)
{
    return (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');
}
vector<string> vw_pair(vector<char> v)
{
    vector<string> ans;
    int n = v.size();
    int sz = 1 << v.size();
    for (int i = 0; i < sz; i++)
    {
        string subset;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                subset.push_back(v[j]);
            }
        }
        if (subset.size())
            ans.push_back(subset);
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s[n];
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        unordered_map<string, int> hsh;
        for (int i = 0; i < n; i++)
        {
            set<char> distinct_vw;
            for (auto ch : s[i])
            {
                if (isVowel(ch))
                {
                    distinct_vw.insert(ch);
                }
            }
            vector<char> vowels;
            for (auto ch : distinct_vw)
            {
                vowels.push_back(ch);
            }

            vector<string> all_subset = vw_pair(vowels);
            for (auto s : all_subset)
            {
                hsh[s]++;
            }
        }
        long long ans = 0;
        for (auto &pr : hsh)
        {
            if (pr.second < 3)
                continue;
            long long ct = pr.second;
            long long ways = ct * (ct - 1) * (ct - 2) / 6;
            if (pr.first.size() % 2 == 0)
                ans -= ways;
            else
                ans += ways;
        }
        cout << ans << endl;
    }
                

    return 0;
}