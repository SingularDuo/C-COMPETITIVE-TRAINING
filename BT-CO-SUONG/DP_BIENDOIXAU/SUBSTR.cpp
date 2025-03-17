#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
void init()
{
    freopen("SUBSTR.inp", "r", stdin);
    freopen("SUBSTR.out", "w", stdout);
    fast;
}
string s;
int n;
int dp_continuous() {
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int max_len = 1;
    for (int i = 0; i < n; i++) dp[i][i] = 1;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = 1;
            max_len = 2;
        }
    }
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = 1;
                max_len = len;
            }
        }
    }
    return max_len;
}

int dp_non_continuous() {
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) dp[i][i] = 1;
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                dp[i][j] = (len == 2) ? 2 : dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][n - 1];
}

signed main() {
    //init();
    fast;
    cin >> s;
    n = s.size();
    
    int ans1 = dp_continuous(); 
    int ans2 = dp_non_continuous(); 

    cout << ans1 << endl;
    cout << ans2 << endl;
}

