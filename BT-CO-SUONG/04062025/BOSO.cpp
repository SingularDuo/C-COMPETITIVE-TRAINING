#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long

static const ll MAX_A = 100000;
void init()
{
    freopen("BOSO.inp", "r", stdin);
    freopen("BOSO.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}
signed main() {
    init();
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll MAXA = 0;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        MAXA = max(MAXA, a[i]);
    }
    vector<vector<ll>> div(MAXA + 1);
    for (ll d = 1; d <= MAXA; d++) {
        for (ll m = d; m <= MAXA; m += d) {
            div[m].push_back(d);
        }
    }

    vector<ll> last_mult(MAXA + 1, 0);
    vector<ll> best_prefix(n, 0);

    for (ll j = 0; j < n; j++) {
        ll curG = 0;
        for (ll d : div[a[j]]) {
            if (last_mult[d] != 0) {
                curG = max(curG, d);
            }
        }

        if (j == 0)
            best_prefix[j] = curG;
        else
            best_prefix[j] = max(best_prefix[j - 1], curG);
        for (ll d : div[a[j]]) {
            last_mult[d] = j + 1;
        }
    }
    vector<ll> last_mult2(MAXA + 1, 0);
    vector<ll> best_suffix(n, 0);

    for (ll k = n - 1; k >= 0; k--) {
        ll curS = 0;
        for (ll d : div[a[k]]) {
            if (last_mult2[d] != 0) {
                curS = max(curS, d);
            }
        }

        if (k == n - 1)
            best_suffix[k] = curS;
        else
            best_suffix[k] = max(best_suffix[k + 1], curS);
        for (ll d : div[a[k]]) {
            last_mult2[d] = k + 1;
        }
    }
    ll res = 0;
    for (ll j = 0; j + 1 < n; j++) {
        res = max(res, best_prefix[j] + best_suffix[j + 1]);
    }

    cout << res << "\n";
    return 0;
}
