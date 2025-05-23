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

void sol() {
    int n, k;
    cin >> n >> k;
    vec(ll, a, n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    int res = 0, l = 0;
    multiset<int> window;
    // ** Su dung sliding window de xu li **
    for (int r = 0; r < n; r++) {
        window.insert(a[r]);
        while (*window.rbegin() - *window.begin() > k) {
            window.erase(window.find(a[l]));
            l++;
        }

        res += (r - l + 1);
    }

    cout << res << endl;
}

KING_PHAT {
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
