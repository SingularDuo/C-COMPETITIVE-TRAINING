#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define endl "\n"
#define min(a, b) min((ll)a, (ll)b)
#define max(a, b) max((ll)a, (ll)b)
void init()
{
    freopen("CREAM.inp", "r", stdin);
    freopen("CREAM.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
signed main()
{
    init();
    int n, m;
    cin >> n >> m;

    set<pair<int, int>> banned;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        banned.insert({min(a, b), max(a, b)});
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            for (int k = j + 1; k <= n; k++)
            {
                if (banned.count({i, j}) == 0 && banned.count({i, k}) == 0 && banned.count({j, k}) == 0)res++;
            }
        }
    }

    cout << res << endl;
}
