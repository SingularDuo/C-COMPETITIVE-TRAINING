#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define vec(type, a, size, value) vector<type> a(size, value);
#define all(x) x.begin(), x.end()
#define I_O(input_name, output_name) freopen((string(input_name) + ".inp").c_str(), "r", stdin); freopen((string(output_name) + ".out").c_str(), "w", stdout); fast;
#define min(a,b) min((ll)a, (ll)b)
#define max(a,b) max((ll)a, (ll)b)
bool multitest = false;
void init()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    fast;
}
void sol() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> dp(n + 1, vector<int>(s + 1, 0)); 
    dp[0][0] = 1;  

    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1;  
        for (int j = 1; j <= s; j++) {
            dp[i][j] = dp[i-1][j];  
            if (j - a[i-1] >= 0) dp[i][j] += dp[i-1][j-a[i-1]];  
        }
    }
    cout << dp[n][s] << endl;
}
KING_PHAT
{
    // set state for multitest
    // multitest = true;
    //set state for I/O style
    I_O("TRAVEL", "TRAVEL");
    fast;
    if (multitest)
    {
        int t;
        cin >> t;
        while (t--)
        {
            sol();
        }
    }
    else
    {
        sol();
    }
    return 0;
}