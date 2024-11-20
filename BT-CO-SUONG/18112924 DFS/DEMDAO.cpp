#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
void init() {
    freopen("BANCO1.inp", "r", stdin);
    freopen("BANCO1.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
const int maxN = 1e6;
bool mark[8][8]; 
int a[8][8];  
int dr[8] = {0, -1, 0, 1, -1, 1, -1, 1}; 
int dc[8] = {-1, 0, 1, 0, 1, 1, -1, -1};
bool ValidCell(int r, int c) {
    return (r >= 0 && r < 8 && c >= 0 && c < 8); //ô ở toạ độ a[r][c] có trên bàn cờ không
}
int DFS(int r, int c) {
    int res = 1; 
    mark[r][c] = true; // đánh dấu đã đi qua
    for (int i = 0; i < 8; ++i) {
        int x = r + dr[i], y = c + dc[i]; // kiểm tra 8 ô xung quanh
        int v = a[r][c];
        if (ValidCell(x, y) && !mark[x][y] && a[x][y] == v) {//nếu thoả Valid (), chưa đi qua và bằng với ô v ở tâm
            res += DFS(x, y);
        }
    }
    return res;
}
int main() {
    init();
    for (int i = 0; i < 8; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++) {
            a[i][j] = s[j] - '0';
        }
    }
    int res = 0; 
    for (int i = 0; i < 8; i++) { 
        for (int j = 0; j < 8; j++) { 
            if (!mark[i][j] && a[i][j] == 1) { 
                res++;
                DFS(i, j);
            }
        }
    }
    cout << res << endl;
    return 0;
}
