#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

void init()
{
    freopen("ROBOT.INP", "r", stdin);
    freopen("ROBOT.OUT", "w", stdout);
    fast;
}

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int m, n;
vector<vector<int>> grid;

bool isValid(int x, int y) {
    return x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0;
}

int bfs() {
    queue<pair<pair<int, int>, pair<int, int>>> q;
    map<pair<pair<int, int>, pair<int, int>>, int> visited;

    q.push({{0, 0}, {m - 1, n - 1}});
    visited[{{0, 0}, {m - 1, n - 1}}] = 0;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int ax = cur.first.first, ay = cur.first.second;
        int bx = cur.second.first, by = cur.second.second;
        int steps = visited[cur];

        if (ax == bx && ay == by) return steps;

        for (int i = 0; i < 4; i++) {
            int nax = ax + dx[i], nay = ay + dy[i];
            int nbx = bx + dx[i], nby = by + dy[i];

            if (!isValid(nax, nay)) nax = ax, nay = ay;
            if (!isValid(nbx, nby)) nbx = bx, nby = by;

            if (!visited.count({{nax, nay}, {nbx, nby}}) && (nax != ax || nay != ay || nbx != bx || nby != by)) {
                visited[{{nax, nay}, {nbx, nby}}] = steps + 1;
                q.push({{nax, nay}, {nbx, nby}});
            }
        }
    }
    return -1;
}

signed main() {
    init();
    fast;
    cin >> m >> n;
    grid.assign(m, vector<int>(n));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];
    if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) {
        cout << "#" << endl;
        return 0;
    }

    int result = bfs();
    if (result == -1) cout << "#" << endl;
    else cout << result / 2 << endl;

    return 0;
}
