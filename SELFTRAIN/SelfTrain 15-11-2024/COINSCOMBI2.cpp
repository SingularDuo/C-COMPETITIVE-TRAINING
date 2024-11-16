#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int MOD = 1e9 + 7;
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int c : coins) {
        for (int j = c; j <= x; j++) {
            dp[j] = (dp[j] + dp[j - c]) % MOD; 
        }
    }
    cout << dp[x] << endl;
    return 0;
}
