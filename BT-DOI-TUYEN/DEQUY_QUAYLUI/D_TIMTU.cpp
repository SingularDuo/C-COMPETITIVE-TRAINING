#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

int n, m;
vector<string> board;
string target;
vector<vector<bool>> visited;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool dfs(int x, int y, int index) {
    if (index == target.size()) return true;
    visited[x][y] = true;
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && board[nx][ny] == target[index]) {
            if (dfs(nx, ny, index + 1)) return true;
        }
    }
    visited[x][y] = false;
    return false;
}

bool exist() {
    visited.assign(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == target[0]) { 
                if (dfs(i, j, 1)) return true;
            }
        }
    }
    return false;
}

KING_PHAT {
    cin >> n >> m;
    board.resize(n);
    for (int i = 0; i < n; i++) cin >> board[i];
    cin >> target;
    if (exist()) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
