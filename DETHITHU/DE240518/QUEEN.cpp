#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MAX = 1005;
int n, m;
int dr[8] = {0, -1, 0, 1, 1, -1, 1, -1};
int dc[8] = {-1, 0, 1, 0, 1, -1, -1, 1};
bool mark[MAX][MAX];
int a[MAX][MAX];

bool ValidCell(int r, int c) {
    return (r >= 1 && r <= n && c >= 1 && c <= m);
}

int DFS(int r, int c) {
    int res = 1;
    mark[r][c] = true;
    for (int i = 0; i < 8; ++i) {
        int x = r + dr[i], y = c + dc[i];
        int v = a[r][c];
        if (ValidCell(x, y) && !mark[x][y] && a[x][y] == v)
            res += DFS(x, y);
    }
    return res;
}

void sol() {
    cin >> n >> m;

    vector<vector<char>> s(n + 1, vector<char>(m + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> s[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == '.') a[i][j] = 1;
            else {
                a[i][j] = -1;
                mark[i][j] = true;
            }
        }
    }

    int b[MAX][MAX] = {0};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!mark[i][j])
                b[i][j] = DFS(i, j);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    sol();
    return 0;
}
