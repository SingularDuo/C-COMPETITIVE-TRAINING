#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

KING_PHAT
{`
    //freopen("WTRANS.INP", "r", stdin);
    //freopen("WTRANS.OUT", "w", stdout);
    fast;

    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> wood;
    vector<vector<ll>> a(n, vector<ll>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] > 0)  
                wood.push_back({i, j}); 
        }
    }
    ll minn = LLONG_MAX;
    for (auto [i, j] : wood) 
    {
        ll curr = 0;
        for (auto [x, y] : wood)
        {
            ll calc = abs(i - x) + abs(j - y);
            curr += calc * a[x][y];
        }
        minn = min(minn, curr);
    }

    cout << minn << endl;
}
