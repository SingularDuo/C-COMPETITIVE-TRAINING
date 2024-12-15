#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
void init() {
    freopen("BAI12.INP", "r", stdin);
    freopen("BAI12.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    init();
    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int maxsum = INT_MIN;
    for (int left = 0; left < n;left++) {
        vector<int> curr(m, 0);
        for (int right = left; right < n; right++) {
            for (int i = 0; i < m; ++i) {
                curr[i] += a[i][right];
            }
            int currsum = curr[0], best_sum = curr[0];
            for (int i = 1; i < m; i++) {
                currsum = max(curr[i], currsum + curr[i]);
                best_sum = max(best_sum, currsum);
            }
            
            maxsum = max(maxsum, best_sum);
        }
    }

    cout << maxsum << endl;
    return 0;
}
