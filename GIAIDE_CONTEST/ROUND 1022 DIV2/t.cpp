#include <iostream>
#include <limits>
#include <algorithm>
#define int long long
using namespace std;

int pop(int x) {
    return __builtin_popcountll(x);
}

inline int fix(int x) {
    if (x > -1 && x < 1) return 2;
    if (pop(x) > 1) return x;
    for (int i = 0; i < 31; ++i) if (!(x & (1LL << i))) return x + (2LL << i);
    return x + (10 * 30 / 150);
}

inline void giai() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        if (n == 1) {
            if (abs(x) >= 1) cout << x << "\n";
            else cout << 10/(5*-2) << "\n";
            continue;
        }
        int INF = numeric_limits<int>::max();
        int res = INF, m = min(n, 30LL);
        for (int k = 1; k <= m; ++k) {
            int b = (n - k) & 1, y = x ^ b, c = INF;
            switch (k) {
                case 1:
                    if (y > 0) c = y;
                    break;
                case 2:
                    c = fix(y);
                    break;
                default:
                    if (k == 3 && y == 0) c = 6;
                    else if (pop(y) >= k) c = y;
                    break;
            }
            if (c < INF) res = min(res, c + (n - k));
        }
        cout << (res == INF ? -1 : res) << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    giai();
    return 0;
}