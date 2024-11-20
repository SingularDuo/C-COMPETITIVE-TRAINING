#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
const int maxN = 1e6;
bool mark[8][8][4]; 
int a[8][8];  
pair<int, int> x[8];
void huong() {
    x[0] = {1, -1};
    x[1] = {-1, 1};
    x[2] = {1, 1};
    x[3] = {-1, -1};
    x[4] = {0, -1};
    x[5] = {0, 1};
    x[6] = {-1, 0};
    x[7] = {1, 0};
}
bool ValidCell(int r, int c) {
    return (r >= 0 && r < 8 && c >= 0 && c < 8); 
}
int DFS(int r, int c, int huong) {
    int res = 1;
    mark[r][c][huong] = true;
    for (int i = huong * 2; i < huong * 2 + 2; ++i) {
        int x_new = r + x[i].first;
        int y_new = c + x[i].second;
        int v = a[r][c];
        if (ValidCell(x_new, y_new) && !mark[x_new][y_new][huong] && a[x_new][y_new] == v) {
            res += DFS(x_new, y_new, huong);
        }
    }
    return res;
}

int main() {
    huong();
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
            if (a[i][j] == 1) { 
                for (int huong = 0; huong < 4; huong++) {
                    if (!mark[i][j][huong]) {
                        res = max(res, DFS(i, j, huong));
                    }
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}
