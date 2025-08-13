#include <bits/stdc++.h>
#include <string>

using namespace std;

#define ll long long
#define int long long
#define vi vector<int>
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
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
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
#define kill cout << "end" << endl;
#define traillingzero(x) __builtin_ctzll(x)
#define count_bit_1(x) __builtin_popcountll(x)
#define leadingzero(x) __builtin_clzll(x)

const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const int INF = INT_MAX;
const int N = 2e5 + 5;
const int LOG = 20;
const double PI = acos(-1);
const double EPS = 1e-9;

void OJ()
{
    fast;
}
void THEMIS()
{
    freopen("text.inp", "r", stdin);
    freopen("text.out", "w", stdout);
    fast;
}
string s;
namespace sub1
{
    bool ok()
    {
        return true;
    }
    void sol()
    {
        cin >> s;
        int n = s.size();
        s = '0' + s;
        vector<pii> p(N + 1);
        p[0].fi = 1;
        p[0].se = 1;
        for (int i = 1; i <= N; i++)
        {
            p[i].fi = (p[i - 1].fi % MOD * 31 % MOD) % MOD;
            p[i].se = (p[i - 1].se % MOD2 * 31 % MOD2) % MOD2;
        }
        vector<pii> hs(n + 1, {0, 0});
        for (int i = 1; i <= n; i++)
        {
            hs[i].fi = (hs[i - 1].fi * 31 + (s[i] - 'a' + 1)) % MOD;
            hs[i].se = (hs[i - 1].se * 31 + (s[i] - 'a' + 1)) % MOD2;
        }

        for (int len = 1; len <= n; len++)
        {
            ll t1 = (hs[len].fi - (hs[0].fi * p[len].fi) % MOD + MOD) % MOD;
            ll t2 = (hs[len].se - (hs[0].se * p[len].se) % MOD2 + MOD2) % MOD2;

            bool valid = true;
            for (int i = len + 1; i <= n; i += len)
            {
                int end = min(i + len - 1, n);
                int riel = end - i + 1;

                if (riel < len)
                {
                    //debug3(len, i, end);
                    ll rem1 = (hs[end].fi - (hs[i - 1].fi * p[riel].fi) % MOD + MOD) % MOD;
                    ll rem2 = (hs[end].se - (hs[i - 1].se * p[riel].se) % MOD2 + MOD2) % MOD2;

                    ll start = (hs[riel].fi - (hs[0].fi * p[riel].fi) % MOD + MOD) % MOD;
                    ll prefix_hash2 = (hs[riel].se - (hs[0].se * p[riel].se) % MOD2 + MOD2) % MOD2;

                    if (rem1 != start || rem2 != prefix_hash2)
                    {
                        
                        valid = false;
                        break;
                    }
                }
                else
                {
                    
                    ll s1 = (hs[end].fi - (hs[i - 1].fi * p[len].fi) % MOD + MOD) % MOD;
                    ll s2 = (hs[end].se - (hs[i - 1].se * p[len].se) % MOD2 + MOD2) % MOD2;

                    if (t1 != s1 || t2 != s2)
                    {
                        valid = false;
                        break;
                    }
                }
            }
            //debug2(len, valid);
            if (valid)
            {
                cout << s.substr(1, len) << endl;
                return;
            }
        }
    }
}

void solve()
{
    if (sub1::ok())
        sub1::sol();
}
__TOISETHIVOI__
{
    int t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
}
