#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define ull unsigned long long
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

void sol()
{
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vi inc(n + 1), dec(n + 1);
    // inc[i] = so luong phan tu tang dan tu 0 -> i
    // dec[i] = so luong phan tu giam dan tu i -> n
    for (int i = 0; i < n; i++)
    {
        inc[i + 1] = inc[i];
        if (i == 0 || a[i] > a[i - 1])
            inc[i + 1]++;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        dec[i] = dec[i + 1];
        if (i == n - 1 || a[i] > a[i + 1])
            dec[i]++;
    }
    int res = -INF;
    for (int i = 0; i < n; i++)
    {
        int v = inc[i] + dec[i];
        if (v > res && v != 0)
        {
            int half = v - 1;
            half /= 2;
            cout<<half<<endl;
            if(inc[i] == half && dec[i] == half) res = v;
        }
        // res = max(res, inc[i] + dec[i]);
    }
    cout << res << endl;
}
__TOISETHIVOI__
{
    int t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++)
    {
        sol();
    }
}