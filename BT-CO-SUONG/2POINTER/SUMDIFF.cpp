#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define vec(type, a, size, value) vector<type> a(size, value);
#define all(x) x.begin(), x.end()
#define I_O(input_name, output_name) freopen((string(input_name) + ".inp").c_str(), "r", stdin); freopen((string(output_name) + ".out").c_str(), "w", stdout); fast;
bool multitest = false;

void init() {
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    fast;
}

void sol() {
    int n;
    cin >> n;
    
    vec(ll, a, n, 0);
    vec(ll, b, n, 0);
    vec(ll, c, n, 0);
    
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    
    sort(all(a));
    sort(all(b));
    sort(all(c));
    
    int res = LLONG_MAX;
    
    for (int i = 0; i < n; i++) {
        int x = a[i];
        auto it_b = upper_bound(all(b), x);
        if (it_b != b.begin()) it_b--;
        int y = *it_b;
        auto it_c = lower_bound(all(c), x);
        int z = (it_c != c.end()) ? *it_c : LLONG_MAX;

        res = min(res, abs(x-y) + abs(y - z) + abs(z-x));
    }

    cout << res << endl;
}

KING_PHAT {
    multitest = false;
    // Set state for multitest
    // multitest = true;
    // Set state for I/O style
    I_O("SUMDIFF", "SUMDIFF");
    fast;
    if (multitest) {
        int t;
        cin >> t;
        while (t--) {
            sol();
        }
    } else {
        sol();
    }
    return 0;
}
