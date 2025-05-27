/*
        _.-- ,.--.
      .'   .'     /
       @       |'..--------._
     /      \._/              '.
    /  .-.-                     \
   (  /    \                     \
   \      '.                  | #
    \       \   -.           /
     :\       |    )._____.'   \
      "       |   /  \  |  \    )
    Kduckp       |   |./'  :__ \.-'
              '--'
*/
/*
 * Author: Kduckp
 * Generated on: 2025-05-14 12:40:12
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define endl "\n"
#define min(a, b) min((ll)a, (ll)b)
#define max(a, b) max((ll)a, (ll)b)
#define fi first
#define se second
#define si size()
#define all(x) x.begin(), x.end()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ull unsigned long long
#define pb push_back
#define __TOISETHIVOI__ signed main()

const int MOD = 1e9 + 7;
const int INF = 2 * 1e18;

void init() {
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    fast;
}
vector<vector<ll>> a(9, vector<ll>(9));
vector<ll> able = {1,2,3,4,5,6,7,8,9};

bool is_valid(ll row, ll col, ll num) {
    for (ll i = 0; i < 9; i++) {
        if (a[row][i] == num || a[i][col] == num) return false;
    }
    
    ll startRow = row - row % 3, startCol = col - col % 3;
    for (ll i = 0; i < 3; i++) {
        for (ll j = 0; j < 3; j++) {
            if (a[startRow + i][startCol + j] == num) return false;
        }
    }
    
    return true;
}
bool solve_sudoku(ll row, ll col) {
    if (row == 9) return true;
    if (col == 9) return solve_sudoku(row + 1, 0);
    if (a[row][col] != 0) return solve_sudoku(row, col + 1);

    for (ll num : able) {
        if (is_valid(row, col, num)) {
            a[row][col] = num;
            if (solve_sudoku(row, col + 1)) return true;
            a[row][col] = 0;
        }
    }
    
    return false;
}

__TOISETHIVOI__ {
    //init();

    for(ll i = 0; i < 9; i++) {
        for(ll j = 0; j < 9; j++) cin >> a[i][j];
    }

    if (solve_sudoku(0, 0)) {
        for(ll i = 0; i < 9; i++) {
            for(ll j = 0; j < 9; j++) cout << a[i][j] << " ";
            cout << endl;
        }
    } 

    return 0;
}