#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
const ll MOD = 1000000007;
const ll maxn = 1e6;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<ll> dp(maxn + 5, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= maxn; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2])%MOD;
    }
    int t;
    cin >> t; 
    while(t--) {
        ll n;
        cin >> n;


        cout << dp[n] << endl; 
    }
    return 0;
}
