#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'


int n, res = 0;
vector<int> col; 

bool check(int row, int c) {
    for (int i = 0; i < row; i++) {
        if (col[i] == c || abs(col[i] - c) == abs(i - row)) {
            return false; 
        }
    }
    return true;
}

void backtrack(int row) {
    if (row == n) {
        res++;
        return;
    }
    for (int c = 0; c < n; c++) {
        if (check(row, c)) {
            col[row] = c; 
            backtrack(row + 1);
            col[row] = -1; 
        }
    }
}

KING_PHAT {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    col.resize(n, -1);
    backtrack(0);
    
    cout << res << '\n';
}
