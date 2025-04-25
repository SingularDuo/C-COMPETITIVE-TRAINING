#include <bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
    int n = grid.size();
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    int size = 0;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        pair<int, int> current = q.front(); 
        int cx = current.first;
        int cy = current.second;
        q.pop();
        size++;

        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny] && grid[nx][ny] == 0) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return size;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<vector<int>> grid(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = (s[j] == '0' ? 0 : 1);
                if (i == j) grid[i][j] = (s[j] == '1' ? 0 : 1);
            }
        }

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int maxSize = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && !visited[i][j]) {
                    maxSize = max(maxSize, bfs(grid, visited, i, j));
                }
            }
        }

        cout << maxSize << endl;
    }

    return 0;
}
