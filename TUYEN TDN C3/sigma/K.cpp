#include <bits/stdc++.h>
using namespace std;

// ========== Type Aliases ==========
#define int long long
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>

// ========== Short Macros ==========
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define si size()
#define endl "\n"

// ========== Loop Macros ==========
#define FOR(i,n)        for (int i = 0; i < n; ++i)
#define REP(i,a,b)      for (int i = a; i <= b; ++i)
#define FORD(i,a,b)     for (int i = a; i >= b; --i)
#define FORDEC(i,a,b,c) for (int i = a; i >= b; i -= c)

// ========== Fast I/O ==========
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// ========== Output Shortcuts ==========
#define yes cout << "YES\n"
#define no cout << "NO\n"

// ========== Custom Macros ==========
#define __TOISETHIVOI__ signed main()
#define vec(a,b,c,d) vector<a> b(c,d)

// ========== Constants ==========
const int MOD = 1e9 + 7;
const int INF = 2e18;
const int N = 2e5 + 5;
const int LOG = 20;
const double PI = acos(-1);
const double EPS = 1e-9;

void init() {
    freopen("K.inp", "r", stdin);
    freopen("K.out", "w", stdout);
    fast;
}

bool can(double x, const vi& v, const vi& w, int k) {
    int n = sz(v);
    vector<double> diff(n);
    FOR(i, n) {
        diff[i] = v[i] - x * w[i];
    }
    sort(all(diff), greater<double>());
    double sum = 0;
    FOR(i, k) sum += diff[i];
    return sum >= 0;
}

__TOISETHIVOI__ {
    init();

    int n, k;
    cin >> n >> k;
    vi v(n), w(n);
    FOR(i, n) cin >> v[i] >> w[i];

    double lo = 0, hi = 1e9;
    FOR(iter, 100) {
        double mid = (lo + hi) / 2;
        if (can(mid, v, w, k)) lo = mid;
        else hi = mid;
    }

    cout << fixed << setprecision(3) << lo << endl;
    return 0;
}
