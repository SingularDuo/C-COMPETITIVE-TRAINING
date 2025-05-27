#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define endl "\n"
#define fi first
#define se second
void init()
{
    freopen("ROLLING.inp", "r", stdin);
    freopen("ROLLING.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
const int movement[4] = {6, 4, 1, 3}; 

signed main()
{
    init();
    int n, k;
    cin >> n >> k;
    
    ll v = 0;
    ll idx = 0;
    
    for (int i = 1; i <= k; i++)
    {
        v += movement[idx];
        idx = (idx + 1) % 4; 
    }

    ll multi = n / k;
    ll res = v * multi;

    ll e_index = multi * k;
    if (e_index < n)
    {
        ll add = n - e_index;
        idx = 0;
        for (int i = 0; i < add; i++)
        {
            res += movement[idx];
            idx = (idx + 1) % 4;
        }
    }

    cout << res << endl;
}
