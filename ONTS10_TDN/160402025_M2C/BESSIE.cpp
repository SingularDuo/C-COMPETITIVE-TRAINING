#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
const int maxn = 100;
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};
bool mark[maxn+1][maxn+1] = {false};
bool ValidCell(int r, int c)
{
    return (r >= 1 && r <= m && c >= 1 && c <= n);
}
int DFS(int r, int c)
{
    int res = 1;
    mark[r][c] = true; 
    for (int i = 0; i < 4; ++i)
    {av
        int x = r + dr[i], y = c + dc[i];
        int v = a[r][c];
        if (ValidCell(x, y) && !mark[x][y] && a[x][y] == v)
        res = res + DFS(x, y);
    }
    return res;
}
KING_PHAT
{
    fast;
    int n, m;
    cin>>n>>m;
    vector<vector<char>> a(n+1, vector<ll>(m+1));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin>>a[i][j];
            // * la da,   . la co, B la chuong, C la vi tri
        }
    }

}