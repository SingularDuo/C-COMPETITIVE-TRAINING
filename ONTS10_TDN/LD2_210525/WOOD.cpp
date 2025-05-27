#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define int long long

const int MOD = 10000007;

signed main() {
	freopen("WOOD.inp", "r", stdin);
	freopen("WOOD.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> he(k);
    
    for (int i = 0; i < k; i++) {
        cin >> he[i];
    }

   
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int h : he) {
            if (i >= h) {
                dp[i] = (dp[i] + dp[i - h]) % MOD;
            }
        }
    }

    cout << dp[n] << endl;
    return 0;
}
