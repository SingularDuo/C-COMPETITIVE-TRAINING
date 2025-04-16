#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

signed main() {
    fast;
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> a(n + 1, vector<pair<int, int>>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j].first;
            a[i][j].second = (i % 2 == j % 2) ? 1 : 2; 
        }
    }

    vector<vector<int>> f_white(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> f_black(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j].second == 1) {
                f_white[i][j] = a[i][j].first + f_white[i - 1][j] + f_white[i][j - 1] - f_white[i - 1][j - 1];
                f_black[i][j] = f_black[i - 1][j] + f_black[i][j - 1] - f_black[i - 1][j - 1];
            } else {
                f_black[i][j] = a[i][j].first + f_black[i - 1][j] + f_black[i][j - 1] - f_black[i - 1][j - 1];
                f_white[i][j] = f_white[i - 1][j] + f_white[i][j - 1] - f_white[i - 1][j - 1];
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int v1 = f_white[x2][y2] - f_white[x1 - 1][y2] - f_white[x2][y1 - 1] + f_white[x1 - 1][y1 - 1];
        int v2 = f_black[x2][y2] - f_black[x1 - 1][y2] - f_black[x2][y1 - 1] + f_black[x1 - 1][y1 - 1];

        cout << abs(v1 - v2) << " ";
    }

    return 0;
}
