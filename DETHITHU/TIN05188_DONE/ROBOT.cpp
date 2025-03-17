#include<bits/stdc++.h>
using namespace std;
void init() {
    freopen("ROBOT.inp", "r", stdin);
    freopen("ROBOT.out", "w", stdout);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int n;
    cin >> n;
    vector<vector<long long>> dp(n, vector<long long>(n, LLONG_MAX));
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    dp[0][0] = 0; 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue; 
            long long best = LLONG_MAX;
            if (j - a >= 0) best = min(best, dp[i][j - a]);
            if (j - b >= 0) best = min(best, dp[i][j - b]);
            if (i - c >= 0) best = min(best, dp[i - c][j]);
            if (i - d >= 0) best = min(best, dp[i - d][j]);
            if (best != LLONG_MAX)  
                dp[i][j] = best + 1;
        }
    }               
    cout << (dp[n - 1][n - 1] == LLONG_MAX ? -1 : dp[n - 1][n - 1]);
    return 0;
}
