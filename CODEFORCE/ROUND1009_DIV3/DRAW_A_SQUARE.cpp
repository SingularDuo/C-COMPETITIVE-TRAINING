#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int l, r, d, u;
        cin >> l >> r >> d >> u;
        if (l == r && d == u && (l * l + d * d == r * r + u * u) && (l + r == u + d))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
