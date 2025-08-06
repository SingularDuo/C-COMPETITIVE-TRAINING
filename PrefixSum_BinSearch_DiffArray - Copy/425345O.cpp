#include <bits/stdc++.h>
using namespace std;

// ========== Type Aliases ==========
#define int long long
#define pii pair<int, int>

// ========== Short Macros ==========
#define all(x) x.begin(), x.end()

// ========== Loop Macros ==========
#define FOR(i,n) for (int i = 0; i < n; ++i)

// ========== Fast I/O ==========
#define fast ios_base::sync_with_stdio(0); cin.tie(0);

#define __TOISETHIVOI__ signed main()

const int INF64 = (int)4e18;

__TOISETHIVOI__ {
    fast;
    int n, p;
    cin >> n >> p;
    vector<pair<int,int>> a(n);
    FOR(i, n) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(all(a));

    vector<int> suff_max(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        suff_max[i] = max(a[i].second, suff_max[i + 1]);
    }

    int best_i = -1, best_j = -1;
    int max_diff = -1;

    for (int i = 0; i < n; ++i) {
        int ipos = a[i].second;
        int target = a[i].first + p;

        auto it = lower_bound(a.begin() + i + 1, a.end(), make_pair(target, -1LL));
        if (it == a.end()) continue;
        int idx = it - a.begin();
        int jpos = suff_max[idx];
        if (jpos <= ipos) continue;
        int diff = jpos - ipos;

        if (diff > max_diff || 
            (diff == max_diff && (ipos < best_i || 
            (ipos == best_i && jpos < best_j)))) {
            max_diff = diff;
            best_i = ipos;
            best_j = jpos;
        }
    }

    if (best_i == -1) {
        cout << 0;
    } else {
        cout << best_i << " " << best_j;
    }
    return 0;
}
