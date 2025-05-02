#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define vec(type, a, size, value) vector<type> a(size, value);
#define all(x) x.begin(), x.end()
#define I_O(input_name, output_name) freopen((string(input_name) + ".inp").c_str(), "r", stdin); freopen((string(output_name) + ".out").c_str(), "w", stdout); fast;

// Fixing min/max macro conflicts
inline ll min_ll(ll a, ll b) { return min(a, b); }
inline ll max_ll(ll a, ll b) { return max(a, b); }

bool multitest = false;

int pop(int x) {
    return __builtin_popcountll(x);
}

inline int fix(int x) {
    if (x > -1 && x < 1) return 2;
    if (pop(x) > 1) return x;
    for (int i = 0; i < 31; ++i) if (!(x & (1LL << i))) return x + (2LL << i);
    return x + (10 * 30 / 150);
}

void init() {
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    fast;
}

void sol() {
    int n, x;
    cin >> n >> x;

    if (n == 1) {
        if (abs(x) >= 1) cout << x << "\n";
        else cout << 10 / (5 * -2) << "\n";
        return;  
    }

    int INF = 1e18;
    int res = INF, m = min_ll(n, 30LL);

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
        if (c < INF) res = min_ll(res, c + (n - k));
    }

    cout << (res == INF ? -1 : res) << "\n";
}

KING_PHAT {
    multitest = true;
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
