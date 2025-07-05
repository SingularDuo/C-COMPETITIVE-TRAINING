/*
        _.-- ,.--.
      .'   .'     /
       @       |'..--------._
     /      \._/              '.
    /  .-.-                     \
   (  /    \                     \
   \      '.                  | #
    \       \   -.           /
     :\       |    )._____.'   \
      "       |   /  \  |  \    )
    Kduckp       |   |./'  :__ \.-'
              '--'
*/
/*
 * Author: Kduckp
 * Generated on: 2025-05-30 23:03:47
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define endl "\n"
#define min(a, b) min((ll)a, (ll)b)
#define max(a, b) max((ll)a, (ll)b)
#define fi first
#define se second
#define si size()
#define all(x) x.begin(), x.end()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ull unsigned long long
#define pb push_back
#define __TOISETHIVOI__ signed main()

const int MOD = 1e9 + 7;
const int INF = 2 * 1e18;

void init() {
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    fast;
}

bool isvalid(int x, int y, int n, int m)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

const int dr[4] = {0, -1, 0, 1};
const int dc[4] = {-1, 0, 1, 0};
int n, m;
vector<vector<ll>> a;
vector<vector<bool>> marked;

int DFS(int r, int c, int &Buffalo, int &Tiger) // Tham chiếu để thay đổi giá trị thật
{
    int res = 1;
    marked[r][c] = true;
    if (a[r][c] == 1) Buffalo++;
    if (a[r][c] == 2) Tiger++;
    for (int i = 0; i < 4; i++)
    {
        int nx = r + dr[i], ny = c + dc[i];
        if (isvalid(nx, ny, n, m) && !marked[nx][ny] && a[nx][ny] >= 0)
        {
            res += DFS(nx, ny, Buffalo, Tiger);
        }
    }
    return res;
}

__TOISETHIVOI__ {
    //init();
    cin >> n >> m;
    a.resize(n, vector<ll>(m));
    marked.resize(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c; cin >> c;
            if (c == '.') a[i][j] = -1;
            else if (c == '*') a[i][j] = 0;
            else if (c == 'x') a[i][j] = 1;
            else a[i][j] = 2;
        }
    }
    int trau = 0, ho = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!marked[i][j] && a[i][j] >= 0)
            {
                int buff = 0, tiger = 0;
                DFS(i, j, buff, tiger);
                if (buff >= tiger * 2) trau += buff;
                else ho += tiger;
            }
        }
    }
    cout << trau << " " << ho;
    return 0;
}
