#include<bits/stdc++.h>
using namespace std;

const int N = 25;

int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };

int n, m;
int a[N][N], grid[N][N];


int cntt(int x, int y) {
    int res = 0;
    for (int i = 0; i < 8; ++i) {
        int u = x + dx[i], v = y + dy[i];
        if (u >= 0 && v >= 0 && u < n && v < m) {
            res += grid[u][v];
        }
    }
    return res;
}

bool notPossible(int i, int j) {
    if (i > 1) {
        for (int y = 0; y < m; ++y) {
            if (cntt(i - 2, y) != a[i - 2][y]) return true;
        }
    }

    if (i > 0 && j > 1) {
        for (int y = 0; y < j - 1; ++y) {
            if (cntt(i - 1, y) != a[i - 1][y]) return true;
        }
    }

    return false;
}

void print_grid() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
}


bool dfs(int i, int j) {
    if (i == n) {
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < m; ++y) {
                if (cntt(x, y) != a[x][y]) return false;
            }
        }
        return true;
    }

    if (notPossible(i, j)) return false;

    int u = i + (j + 1) / m;
    int v = (j + 1) % m;

    for (int k = 0; k <= 1; ++k) {
        grid[i][j] = k;
        if (dfs(u, v)) return true;
    }

    return false;
}

void solve() {
    if (dfs(0, 0)) print_grid();
    else cout << "No solution\n";
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    solve();
    return 0;
}
