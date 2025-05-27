#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define endl "\n"
#define min(a, b) min((ll)a, (ll)b)
#define max(a, b) max((ll)a, (ll)b)
void init()
{
    freopen("BONUS.INP", "r", stdin);
    freopen("BONUS.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
signed main()
{
    init();
    int n; 
    cin >> n;
    
    vector<vector<ll>> a(n+2, vector<ll>(n+2));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++) cin >> a[i][j];
    }

    vector<vector<ll>> f(n+2, vector<ll>(n+2, 0));

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + a[i][j];
        }
    }

    ll res = LLONG_MIN;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int x = i; x <= n; x++)
            {
                for(int y = j; y <= n; y++)
                {
                    ll square_size = abs(x - i) + 1;
                    ll v = f[x][y] - f[i-1][y] - f[x][j-1] + f[i-1][j-1];

                    for(int l = square_size; l > 0; l -=2)
                    {
                        if (x-l >= 1 && y-l >= 1) 
                        {
                            v -= (f[x-l][y] - f[i-1][y] - f[x-l][j-1] + f[i-1][j-1]);
                        }
                    }

                    res = max(res, v);
                }
            }
        }
    }

    cout << res << endl;
}
