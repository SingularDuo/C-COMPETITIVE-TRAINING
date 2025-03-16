#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};  
int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};  

int n, m;
int need = 1;
vector<vector<ll>> a;  
vector<vector<bool>> visited; 

bool ValidCell(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < m && !visited[r][c]); 
}

void knights(ll curr_x, ll curr_y, ll times) {
    a[curr_x][curr_y] = times;
    visited[curr_x][curr_y] = true;

    if (times == need) { 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        exit(0); 
    }

    for (int i = 0; i < 8; i++) {
        int nx = curr_x + dx[i];
        int ny = curr_y + dy[i];

        if (ValidCell(nx, ny)) {
            knights(nx, ny, times + 1);
        }
    }
    a[curr_x][curr_y] = 0;
    visited[curr_x][curr_y] = false;
}

KING_PHAT {
    fast;
    cin >> n >> m;
    need = n * m;

    a.assign(n, vector<ll>(m, 0));
    visited.assign(n, vector<bool>(m, false));

    knights(0, 0, 1); 

    cout << "-1\n";
}
