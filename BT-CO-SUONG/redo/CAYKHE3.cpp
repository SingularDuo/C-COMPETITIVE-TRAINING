#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> W(n + 1, 0);
    vector<int> V(n + 1, 0);
    vector<int> A(n + 1, 0);

    for(int i = 1; i <= n; ++i) {
        cin >> W[i] >> V[i] >> A[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; ++i) {
        for(int w = 0; w <= m; ++w) {
            dp[i][w] = dp[i - 1][w];

            for(int k = 1; k <= A[i]; ++k) {
                if(w >= k * W[i]) {
                    dp[i][w] = max(dp[i][w], dp[i - 1][w - k * W[i]] + k * V[i]);
                }
            }
        }
    }
    cout << dp[n][m] << "\n";

    return 0;
}
