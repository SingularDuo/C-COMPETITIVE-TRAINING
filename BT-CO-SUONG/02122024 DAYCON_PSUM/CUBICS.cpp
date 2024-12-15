#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

void init(){
    freopen("CUBICS.inp", "r", stdin);
    freopen("CUBICS.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    init();
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        a[i] = x - k;
    }

    vector<ll> psum(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        psum[i] = psum[i - 1] + a[i];
    }

    unordered_map<ll, ll> prefix_count;
    prefix_count[0] = 0; 
    ll maxx = 0, minn = -1;
    for (ll i = 1; i <= n; i++) {
        if (prefix_count.find(psum[i]) == prefix_count.end()) {
            prefix_count[psum[i]] = i;
        } else {
            ll cnt = i - prefix_count[psum[i]];
            if (cnt > maxx) {
                maxx = cnt;
                minn = prefix_count[psum[i]] + 1; 
            }
        }
        prefix_count[psum[i]] = i;
    }

    cout << maxx << " " << minn << endl;

    return 0;
}
