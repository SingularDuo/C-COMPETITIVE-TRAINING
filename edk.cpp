#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define vvi vector<vi>
#define vii vector<pii>
#define ull unsigned long long
#define ld long double
#define setp(x) fixed << setprecision(x)
#define setp2(x, y) fixed << setprecision(x) << y
#define endl "\n"
#define __TOISETHIVOI__ signed main()
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fi first
#define se second
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define YESNO(x) cout << ((x) ? "YES\n" : "NO\n")
#define debug(x) cerr << #x << " = " << x << endl
#define debug2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define debug3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define kill cout<<"end"<<endl;

const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const int INF = LLONG_MAX / 4;
const int N = 2e5 + 5;
const int LOG = 20;
const double PI = acos(-1);
const double EPS = 1e-9;

void OJ() { fast; }
void THEMIS() {
    freopen("text.inp", "r", stdin);
    freopen("text.out", "w", stdout);
    fast;
}

void sol() {
    int n, m; 
    cin >> n >> m;
    vi tr(n);
    vector<vi> a(n);
    for (int i = 0; i < n; i++) {
        int t, k;
        cin >> t >> k;
        tr[i] = t;
        a[i].resize(k);
        for (int j = 0; j < k; j++) cin >> a[i][j];
        sort(all(a[i])); 
    }

    int maxTime = 0;
    for (auto &v : a) if (!v.empty()) maxTime = max(maxTime, v.back());

    vector<vi> dp(n + 1, vi(maxTime + 1, -INF)); 
    dp[0][0] = 0;

    dp[1][0] = a[1][0];
    for (int t = 1; t <= maxTime; t++)
    {
        dp[1][t] = dp[1][t - 1] + a[0][t - 1];
    }


    for (int i = 2; i <= n; i++) {
        for (int t = 0; t <= maxTime; t++) {
            // không đón thêm ở điểm i-1
            dp[i][t] = max(dp[i][t], dp[i-1][t]);

            // đón ở điểm i-1 nếu đủ thời gian di chuyển
            if (t >= tr[i-1]) {
                for (int v = 0; v <= t - tr[i-1]; v++) {
                    int cnt = upper_bound(all(a[i-1]), v) - a[i-1].begin();
                    dp[i][t] = max(dp[i][t], dp[i-1][t - tr[i-1]] + cnt);
                }
            }
        }
    }

    int res = 0;
    for (int t = 0; t <= maxTime; t++) res = max(res, dp[n][t]);
    cout << res;
}

__TOISETHIVOI__ {
    int t = 1;
    // cin >> t;
    while (t--) sol();
}
