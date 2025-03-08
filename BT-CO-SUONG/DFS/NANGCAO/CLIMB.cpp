#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

const int maxn = 1005;
int n, m;
int ans = 0;
vector<vector<int>> path;  
vector<vector<int>> dp;  
vector<vector<bool>> mark;
void init()
{
    freopen("CLIMB.INP", "r", stdin);
    freopen("CLIMB.OUT", "w", stdout);
    fast;
}
bool ValidCell(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < m);
}
const int dr[4] = {0, -1, 0, 1}; 
const int dc[4] = {-1, 0, 1, 0};
int DFS(int row, int col) {
    if (dp[row][col] != -1) return dp[row][col];  

    dp[row][col] = 1;
    for (int i = 0; i < 4; i++) {
        int r = row + dr[i];
        int c = col + dc[i];
        if (ValidCell(r, c) && path[r][c] > path[row][col]) {
            dp[row][col] = max(dp[row][col], 1 + DFS(r, c));
        }
    }
    return dp[row][col];
}

KING_PHAT {
    init();
    fast;
    cin >> n >> m;
    path.assign(n, vector<int>(m));
    dp.assign(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> path[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans = max(ans, DFS(i, j)); 

    cout << ans << endl;
}
