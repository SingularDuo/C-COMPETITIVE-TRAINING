#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fi first
#define se second
#define int long long
vector<bool> used(3, false);
signed main()
{
    ll n;
    cin>>n;
    //code brute xem dc nhieu
    vector<vector<ll>> a (n, vector<ll>(3));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)cin>>a[i][j];
    }

    ll res = 0;
    for(int i = 0; i < n; i++)
    {
        ll val = LLONG_MIN, pos;
        for(int j = 0; j < 3; j++)
        {
            if(a[i][j] > val && used[j] == false)
            {
                val = a[i][j];
                pos = j;
            }
        }
        res += val;
        fill(used.begin(), used.end(), false);
        used[pos] = true;

    }
    cout<<res;
}
/*
Im so sorry but this is an 2d array DP, which i havent learn about so much, i will make another video to solve it later, tysm.
*/
