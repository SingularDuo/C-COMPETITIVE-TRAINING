#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
void init()
{
    freopen("BFS01_G.INP", "r", stdin);
    freopen("BFS01_G.OUT", "w", stdout);
    fast;
}
const int maxn = 1005;
int n, m;
vector<vector<char>> grid;
vector<vector<bool>> mark;
int min_black = LLONG_MAX;

const int dr[4] = {0, -1, 0, 1}; 
const int dc[4] = {-1, 0, 1, 0};

bool ValidCell(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < m);
}

void DFS(int r, int c, int black_count) {
    if (r == n - 1 && c == m - 1) { 
        min_black = min(min_black, black_count);
        return;
    }

    mark[r][c] = true;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if (ValidCell(nr, nc) && !mark[nr][nc]) {
            DFS(nr, nc, black_count + (grid[nr][nc] == '*' ? 1 : 0));
        }
    }
    mark[r][c] = false;
}

signed main() {
    init();
    fast;
    cin >> n >> m;
    grid.assign(n, vector<char>(m));
    mark.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    DFS(0, 0, (grid[0][0] == '*' ? 1 : 0));

    cout << min_black << endl;
}
