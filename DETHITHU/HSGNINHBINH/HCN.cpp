#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl "\n"

void init()
{
    freopen("HCN.INP", "r", stdin);
    freopen("HCN.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

signed main()
{
    init();
    ll n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    ll res = 0, cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 1)
            {
                int right = j, down = i;
                while (right < n && a[i][right] == 1) right++;
                while (down < n && a[down][j] == 1) down++;

                for (int x = i; x < down; x++){
                    for (int y = j; y < right; y++)a[x][y] = 0;
                }
                ll area = (right - j) * (down - i);
                res = max(res, area);
                cnt++;
            }
        }
    }

    cout << cnt << endl << res;
}
