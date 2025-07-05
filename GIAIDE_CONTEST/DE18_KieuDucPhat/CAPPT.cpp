#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define all(x) x.begin(), x.end()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define __TOISETHIVOI__  signed main()
const int MOD = 1e9 + 7;
const int InF = 2 * 1e18;

void init() {
    freopen("CAPPT.INP", "r", stdin);
    freopen("CAPPT.OUT", "w", stdout);
    fast;
}

__TOISETHIVOI__ {
    init();
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> freq;

    vector<int> arr(n);
    for (int &x : arr) cin >> x;
    int res = 0;
    for (int i = 0; i < n;i++) {
        int curr = arr[i];
        int comp = k - curr;
        if (freq.find(comp) != freq.end()) {
            res += freq[comp];
        }
        freq[curr]++;
    }
    cout << res;

    return 0;
}
