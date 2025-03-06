#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int n = 8;
vector<vector<bool>> a(n, vector<bool>(n, 0));
string s;
int res = 0;

bool validcell(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n && !a[x][y]);
}
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char dir[4] = {'D', 'U', 'L', 'R'};

void gen(int x, int y, int idx) {
    if (x == n - 1 && y == 0) { 
        if (idx == s.size()) res++;
        return;
    }
    
    if (idx >= s.size()) return;
    a[x][y] = 1; 
    
    bool dead_end = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (validcell(nx, ny)) {
            dead_end = false;
            break;
        }
    }

    if (!dead_end) {
        if (s[idx] != '?') {
            for (int i = 0; i < 4; i++) {
                if (s[idx] == dir[i]) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (validcell(nx, ny)) gen(nx, ny, idx + 1);
                }
            }
        } else {
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (validcell(nx, ny)) gen(nx, ny, idx + 1);
            }
        }
    }

    a[x][y] = 0;
}

signed main() {
    fast;
    cin >> s;
    gen(0, 0, 0); // Sửa điểm bắt đầu về (0,0) để phù hợp với yêu cầu bài toán
    cout << res;
}
