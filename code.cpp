#include<bits/stdc++.h>

using namespace std;

#define ll long long
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
const int INF = INT_MAX;
const int N = 5000;
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
    string s,t; cin>>s>>t;
    // => dp[i][j] la so thao tac toi thieu can de chuyen i phan tu dau tien cua s thanh j phan tu dau tien cua t
    int n = s.size(), m = t.size();
    vvi dp(n + 1, vi(m + 1, 0));
    dp[0][0] = 0;
    for(int i = 0; i <= n; i++)dp[i][0] = i;
    for(int j = 0; j <= m; j++)dp[j][0] = j;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(s[i] == t[j])
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else
            {
                if(i != 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1); // xoa
                if(j != 0)dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1); // them
                if(i != 0 && j != 0)
                {
                    int v = dp[i-1][j-1] + (s[i] != t[j]); // thay the
                    dp[i][j] = min(dp[i][j], v);
                }
            }
        }
    }
    cout<<dp[n][m]<<endl;

}
__TOISETHIVOI__
{
    int t = 1;
    // cin >> t;
    for(int i = 0; i < t; i++)
    {
        sol();
    }
}