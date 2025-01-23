#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
void init(){
    freopen("DPB1.INP", "r", stdin);
    freopen("DP_B1.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tier(0);
}
int main() {
    init();
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> dp(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    ll max_length = *max_element(dp.begin(), dp.end());
    cout << max_length << endl;

    return 0;
}
