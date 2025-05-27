#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k; 
    cin >> n >> k;
    vector<int> a(n), f(n), f_chan(n), res;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f[i] = (i == 0) ? a[i] : f[i - 1] + a[i];
        f_chan[i] = (a[i] % 2 == 0) ? ((i == 0) ? 1 : f_chan[i - 1] + 1) : ((i == 0) ? 0 : f_chan[i - 1]);
    }

    ll maxx = LLONG_MIN, max_chan = 0;

    for (int i = 0; i <= n - k; i++) {
        ll v = f[i + k - 1] - (i == 0 ? 0 : f[i - 1]);
        maxx = max(maxx, v);
    }

    for (int i = 0; i <= n - k; i++) {
        ll v = f[i + k - 1] - (i == 0 ? 0 : f[i - 1]);
        if (v == maxx) {
            int cnt = f_chan[i + k - 1] - (i == 0 ? 0 : f_chan[i - 1]);
            res.push_back(i);
            max_chan = max(max_chan, cnt);
        }
    }

    if (res.size() == 1) {
        cout << res[0] + 1 << " " << res[0] + k;
        return 0;
    }

    for (int i : res) {
        int cnt = f_chan[i + k - 1] - (i == 0 ? 0 : f_chan[i - 1]);
        if (cnt == max_chan) {
            cout << i + 1 << " " << i + k << endl;
            return 0;
        }
    }

    return 0;
}
