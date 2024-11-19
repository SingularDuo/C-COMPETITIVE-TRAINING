#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main() {
    int n;
    cin >> n;
    vector<ll> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];
    vector<ll> prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + vec[i - 1];
    }
    int t;
    cin >> t;
    vector<pair<ll, ll>> luu(t);
    for (int i = 0; i < t; i++) cin >> luu[i].first >> luu[i].second;
    for (int i = 0; i < t; i++) {
        ll l = luu[i].first - 1;
        ll r = luu[i].second - 1;
        ll sum = prefix_sum[r + 1] - prefix_sum[l];
        cout << sum << endl;
    }

    return 0;
}
