#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    vector<int> dp(x + 1, x + 1);
    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        for (int coin : coins) {
            if (i - coin >= 0) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    if (dp[x] == x + 1) {
        cout << -1 << endl;
    } else {
        cout << dp[x] << endl;
    }

    return 0;
}
