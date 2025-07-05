#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main() {
    string s; cin >> s;
    int n = s.size();
    vector<ll> dp(n, 0);
    vector<vector<bool>> is_pal(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) is_pal[i][i] = true;

    for (int i = 0; i < n - 1; i++) is_pal[i][i + 1] = (s[i] == s[i + 1]);

    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            is_pal[i][j] = (s[i] == s[j]) && is_pal[i + 1][j - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        dp[i] = i + 1;
        if (is_pal[0][i])
            dp[i] = 1;
        else {
            for (int j = 1; j <= i; j++) {
                if (is_pal[j][i])
                    dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
    }

    cout << dp[n - 1] << endl;
    return 0;
}
