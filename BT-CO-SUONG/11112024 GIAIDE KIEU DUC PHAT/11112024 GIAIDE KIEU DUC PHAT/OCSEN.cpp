#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init(){
    freopen("OCSEN.inp", "r", stdin);
    freopen("OCSEN.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
    init();
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<vector<int>> a(n + 2, vector<int>(m + 2, 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    if (a[x][y] == 1) {
        cout << "-1" << endl;
        return 0;
    }
    queue<pair<int, int>> q;
    q.push({x, y});
    a[x][y] = 1; 
    int count = 0;
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        count++;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (a[nx][ny] == 0) {
                q.push({nx, ny});
                a[nx][ny] = 1;
            }
        }
    }
    
    cout << count << endl;
    return 0;
}
