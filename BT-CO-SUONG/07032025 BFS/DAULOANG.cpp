#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
void init()
{
    freopen("DAULOANG.INP", "r", stdin);
    freopen("DAULOANG.OUT", "w", stdout);
    fast;
}
const int dr[4] = {0, -1, 0, 1}; 
const int dc[4] = {-1, 0, 1, 0};

int n, m;
vector<vector<int>> grid;
vector<vector<bool>> visited;

bool ValidCell(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < m);
}

int BFS(int r, int c) {
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = true;
    int size = 1;
    bool on_border = (r == 0 || r == n - 1 || c == 0 || c == m - 1);

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dr[i], ny = y + dc[i];
            if (ValidCell(nx, ny) && grid[nx][ny] == 1 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                size++;
                if (nx == 0 || nx == n - 1 || ny == 0 || ny == m - 1) {
                    on_border = true;
                }
            }
        }
    }

    return on_border ? size : 0;
}

signed main() {
    init();
    fast;
    cin >> n >> m;
    grid.assign(n, vector<int>(m));
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    map<int, int> size_count; // Tự động sắp xếp tăng dần
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                int size = BFS(i, j);
                if (size > 0) {
                    count++;
                    size_count[size]++;
                }
            }
        }
    }

    cout << count << endl;

    for (auto [size, freq] : size_count) {
        cout << size << " " << freq << endl;
    }
}
