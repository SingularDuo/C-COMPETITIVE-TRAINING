#include <bits/stdc++.h>
using namespace std;
#define ll long long
void init() {
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main() {
    init();
    ll n;
    cin >> n;
    vector<pair<ll, pair<ll, ll>>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second.first >> a[i].second.second; 
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    ll current = 0, bucket = 0;

    for (int i = 0; i < n; i++) {
        current = a[i].second.first;
        bucket = a[i].second.second; 
        ans = max(ans, bucket);
        if (i + 1 < n && a[i + 1].first <= current) {
            bucket += a[i + 1].second.second;
            ans = max(ans, bucket);
        }
        if (i - 1 >= 0 && a[i - 1].second.first < current) {
            bucket = max(0LL, bucket - a[i - 1].second.second);
            ans = max(ans, bucket);
        }
    }

    cout << ans << endl;
    return 0;
}
