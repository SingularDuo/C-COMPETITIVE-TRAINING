#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
void init()
{
    freopen("NKPALIN.inp", "r", stdin);
    freopen("NKPALIN.out", "w", stdout);
    fast;
}
signed main() {
    fast;
    //init();
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) dp[i][i] = 1; 
    
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                dp[i][j] = (len == 2) ? 2 : dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    int i = 0, j = n - 1;
    string palin1 = "", palin2 = "";
    
    while (i <= j) {
        if (s[i] == s[j]) { 
            palin1 += s[i];  
            if (i != j) palin2 = s[j] + palin2; 
            i++, j--;
        } else {
            if (dp[i + 1][j] > dp[i][j - 1])
            {
                i++;
            }
            else j--;
        }
    }

    cout << palin1 + palin2 << endl;
}
