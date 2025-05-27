#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

vector<vector<int>> chess(8, vector<int>(8, 1)); 
int ans = 0;


bool is_safe(vector<int> &cols, int row, int col) {
    for (int r = 0; r < row; r++) {
        int c = cols[r];
        if (c == col || abs(r - row) == abs(c - col))
            return false;
    }
    return true;
}


void solve(int row, vector<int> &cols) {
    if (row == 8) {
        ans++;
        return;
    }
    for (int col = 0; col < 8; col++) {
        if (chess[row][col] == 0) continue;
        if (is_safe(cols, row, col)) {
            cols[row] = col;
            solve(row + 1, cols);
            cols[row] = -1;
        }
    }
}

signed main() {

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char c; cin >> c;
            if (c == '*') chess[i][j] = 0;
        }
    }

    vector<int> cols(8, -1); 
    solve(0, cols);
    cout << ans << endl;
}
