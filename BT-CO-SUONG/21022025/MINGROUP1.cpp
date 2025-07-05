#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int int64_t  
#define ll long long

const int dr[4] = {0, -1, 0, 1};
const int dc[4] = {-1, 0, 1, 0};
void init()
{
    freopen("TRAUVAHO.INP", "r", stdin);
    freopen("TRAUVAHO.OUT", "w", stdout);
    fast;
}
int m, n;
vector<vector<int>> a;
vector<vector<bool>> mark;

bool ValidCell(int r, int c) {
    return (r >= 0 && r < m && c >= 0 && c < n);
}

void DFS(int r, int c, int &counttrau, int &countho) {
    mark[r][c] = true;
    if (a[r][c] == 1) counttrau++;
    if (a[r][c] == 2) countho++;

    for (int i = 0; i < 4; ++i) {
        int x = r + dr[i], y = c + dc[i];
        if (ValidCell(x, y) && !mark[x][y] && a[x][y] >= 0) {
            DFS(x, y, counttrau, countho);
        }
    }
}

signed main() {
    //init();
    fast;
    cin >> m >> n;
    
    a.assign(m, vector<int>(n));
    mark.assign(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char s;
            cin >> s;
            if (s == '*') a[i][j] = 0;  // Đất
            else if (s == '.') a[i][j] = -1;
            else if (s == 'x') a[i][j] = 1;  // Trâu rừng
            else if (s == 'o') a[i][j] = 2;  // Hổ
        }
    }

    int trau = 0, ho = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!mark[i][j] && a[i][j] > 0) {
                int currenttrau = 0, currentho = 0;
                DFS(i, j, currenttrau, currentho);
                if (currenttrau >= currentho * 2) trau += currenttrau;
                else ho += currentho;
            }
        }
    }
    cout << trau << " " << ho;
}
