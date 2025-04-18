#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
struct customer
{
    int max_a1, max_a2;
};
KING_PHAT
{
    fast;
    int t;
    cin>> t;
    while(t--)
    {
        int n, k;
        cin>> n >> k;
        vector<customer> a(n);
        for(int i = 0; i < n; i++)
        {
            cin>> a[i].max_a1 >> a[i].max_a2;
        }
        sort(a.begin(), a.end());
        ll max_end = n - 1 - k;
        ll res = a[max_end-1];
        ll res = 0;
        for(int i = 0; i < n; i++)
        {
            if(a[i])
        }
    }
}