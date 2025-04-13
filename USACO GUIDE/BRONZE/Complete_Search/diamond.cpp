#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, k, res = 0;
vector<ll> a, current;

void gen(ll idx) {
    res = max(res, (ll)current.size());

    for (ll i = idx; i < n; i++) {
        if (current.empty() || a[i] <= current.front() + k) {
            current.push_back(a[i]);
            gen(i + 1);
            current.pop_back();
        }
    }
}

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    a.resize(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    if(n <= 500)
    {
        sort(a.begin(), a.end());
        gen(0);
        cout << res << endl;
        return 0;
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll curr = 1;
        ll val = a[i] + k;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > val) break;
            curr++;
        }
        ans = max(ans, curr);
    }
    cout << ans << endl;

    return 0;
}
