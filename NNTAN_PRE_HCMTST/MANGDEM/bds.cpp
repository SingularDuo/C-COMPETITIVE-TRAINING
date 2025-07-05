#pragma GCC optimize("O2", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 2e6 + 5;

int n;
int a[N];
int pos[N];

signed main() {
    freopen("BAIDESAI.INP", "r", stdin);
    freopen("BAIDESAI.OUT", "w", stdout);
    fast;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    int res = 0;

    for (int x = 1; x * x <= 2 * n; ++x) {
        for (int y = x + 1; x * y <= 2 * n; ++y) {
            int i = pos[x], j = pos[y];
            if (i < j && x * y == i + j) res++;
        }
    }

    cout << res << '\n';
    return 0;
}
