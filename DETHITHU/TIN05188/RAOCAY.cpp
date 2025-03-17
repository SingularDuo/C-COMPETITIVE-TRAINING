#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KInG_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

using namespace std;
void init()
{
    freopen("RAOCAY.inp", "r", stdin);
    freopen("RAOCAY.out", "w", stdout);
    fast;
}
signed main() {
    init();
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    int rao = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int current = 0;
            if (grid[i][j] == 1) {
                if (i == 0 || grid[i - 1][j] == 0) current++; 
                if (i == m - 1 || grid[i + 1][j] == 0) current++;
                if (j == 0 || grid[i][j - 1] == 0) current++; 
                if (j == n - 1 || grid[i][j + 1] == 0) current++;
            }
            rao+= current;
        }
    }

    cout << rao << endl;
    return 0;
}
