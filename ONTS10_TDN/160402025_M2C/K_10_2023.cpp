#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
const int MOD = 1e9;

int mx[] = {-1, 1, 2, 2};
int my[] = {2, 2, 1, -1};

int m, n, k, q;
int res = 0;
bool finished = false;


void calculate(vector<vector<ll>> &a, int x, int y)
{
    if (finished) return;
    if (x == m && y == n)
    {
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + mx[i];
        int ny = y + my[i];
        if (nx >= 1 && nx <= m && ny >= 1 && ny <= n && a[nx][ny] != -1 )
        {
            
            a[nx][ny] ++; 
            //cout<<nx<<" "<<ny<<" "<<a[nx][ny]<<endl;
            calculate(a, nx, ny);
            //a[nx][ny] -= a[x][y];
        }
        
    }
}

KING_PHAT
{
    fast;
    cin >> m >> n >> k >> q;
    vector<vector<ll>> a(m + 1, vector<ll>(n + 1, 0));
    while (k--)
    {
        int kx, ky;
        cin >> kx >> ky;
        a[kx][ky] = -1; 
    }

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (a[x][y] == -1 || a[m][n] == -1)
        {
            cout << 0 << endl;
            continue;
        }

        a[x][y] = 1; 
        calculate(a, x, y);
        cout << a[m][n] << endl;
        for(auto& i : a)
        {
            for(auto& j : i)
            {
                if(j != -1)j = 0;
            }
        }
        finished = false;
        res = 0;
    }
}
