#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main() {
    int n, x;
    cin >> n >> x;
    vector<ll> price(n), page(n);
    for (int i = 0; i < n; i++) cin >> price[i];
    for (int i = 0; i < n; i++) cin >> page[i];
    vector<ll> dp(x + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = x; j >= price[i]; j--) {
            dp[j] = max(dp[j], dp[j - price[i]] + page[i]);
        }
    }
    cout << dp[x] << endl;
    return 0;
}
