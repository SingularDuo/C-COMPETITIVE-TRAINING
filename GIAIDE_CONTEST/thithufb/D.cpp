#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"
#define int long long
const int MOD = 1e9 + 7;
signed main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);

    int l, r, k;
    cin >> l >> r >> k;

    ll res = 0;

    for (int i = l; i <= r; i++)
    {
        for (int j = 1; j <= r; j++)
        {
            for (int x = 1; x <= r; x++)
            {
                for (int u = 1; u <= r; u++)
                {
                    ll v = __gcd(i, j);
                    ll v2 = __gcd(v, x);
                    ll v3 = __gcd(v2, u);

                    if (v3 == k) res++;
                }
            }
        }
    }

    cout << res %  MOD;
}
