#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main() {
    fastio;
    int n;
    cin >> n;
    const int MAX_SIZE = 1001; 
    vector<vector<int>> a(MAX_SIZE, vector<int>(MAX_SIZE, 0));

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;



        for (int j = min(x1, x2); j <= max(x1, x2); j++) {
            for (int k = min(y1, y2); k <= max(y1, y2); k++) {
                a[j][k] = 1; 
            }
        }
    }

    int res = 0;
    for (int i = 1; i < MAX_SIZE; i++) { 
        for (int j = 1; j < MAX_SIZE; j++) {
            if (a[i][j] == 1) res++;
        }
    }

    cout << res << endl;

    return 0;
}
