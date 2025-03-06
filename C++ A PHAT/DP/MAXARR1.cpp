#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
const int maxn = 100000;
KING_PHAT
{
    fast;
    int t;
    vector<ll> a(maxn + 1);
    a[0] = 0, a[1] = 1;
    ll res = 1; 
    for (int i = 2; i <= maxn; i++)
    {
        if (i % 2 == 0)
            a[i] = a[i / 2];
        else
            a[i] = a[i / 2] + a[i / 2 + 1];

    }
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << a[n] << endl;
    }
}
