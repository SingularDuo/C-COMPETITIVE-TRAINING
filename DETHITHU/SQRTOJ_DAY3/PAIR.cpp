#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl "\n"

void init()
{
    freopen("PAIR.inp", "r", stdin);
    freopen("PAIR.out", "w", stdout);
    ios_base::sync_with_stdio(0);
}

signed main() {
    init();
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    ll max_value = pow(2,k);
    vector<ll> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    while (m--) {
        ll u, v;
        cin >> u >> v;
        a[u - 1] = v;

        ll res = 0;
        map<int, int> dong_du;
        for (int i = 0; i < n; i++) dong_du[a[i] % max_value]++;

        vector<pair<int, int>> freq;
        for (auto &it : dong_du) freq.push_back(it);

        int d = freq.size();
        for (int i = 0; i < d; i++) {
            ll mod1 = freq[i].first, count1 = freq[i].second;
            for (int j = i; j < d; j++) {
                ll mod2 = freq[j].first, count2 = freq[j].second;
                if ((mod1 * mod2) % max_value == 0) {
                    if (mod1 == mod2)
                        res += count1 * (count1 - 1) / 2;
                    else
                        res += count1 * count2;
                }
            }
        }

        cout << res << endl;
    }

    return 0;
}
