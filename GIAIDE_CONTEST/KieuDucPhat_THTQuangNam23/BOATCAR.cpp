#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
void init()
{
    freopen("BOATCAR.inp", "r", stdin);
    freopen("BOATCAR.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void sol() {
    int n, Q;
    cin >> n >> Q;
    vector<int> K(n), U(n);
    for (int i = 0; i < n; i++) {
        cin >> K[i] >> U[i];
    }

    vector<int> dp(Q + 1, 0);
    
    for (int i = 0; i < n; i++) {
        for (int j = Q; j >= K[i]; j--) {
            dp[j] = max(dp[j], dp[j - K[i]] + U[i]);
        }
    }

    cout << dp[Q] << endl;
}

int main() {
    init();
    fast;
    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}
