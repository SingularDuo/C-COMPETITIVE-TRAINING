#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

ll x;
vector<ll> sumA, sumB;
vector<ll> b, c;

void backtrack(int idx, ll curr, int type) {
    if (curr > x) return;

    if (type == 1) {
        if (idx == b.size()) {
            sumA.push_back(curr);
            return;
        }
    } else {
        if (idx == c.size()) {
            sumB.push_back(curr);
            return;
        }
    }

    if (type == 1)
        backtrack(idx + 1, curr + b[idx], type);
    else
        backtrack(idx + 1, curr + c[idx], type);
    backtrack(idx + 1, curr, type);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    cin >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int k = n / 2;
    for (int i = 0; i < k; i++) b.push_back(a[i]);
    for (int i = k; i < n; i++) c.push_back(a[i]);

    backtrack(0, 0, 1);
    backtrack(0, 0, 2);

    sort(sumB.begin(), sumB.end());

    ll res = 0;
    for (ll sa : sumA) {
        ll need = x - sa;
        auto it = lower_bound(sumB.begin(), sumB.end(), need);
        while (it != sumB.end() && *it == need) {
            res++;
            it++;
        }
    }

    cout << res << endl;

    return 0;
}
