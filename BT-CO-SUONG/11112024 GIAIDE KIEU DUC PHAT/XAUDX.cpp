#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init(){
    freopen("XAUDX.inp", "r", stdin);
    freopen("XAUDX.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int longestPalindromeSubstring(string s) {
    int n = s.length();
    if (n == 0) return 0;

    int maxx = 1; 
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            maxx = 2;
        }
    }
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                maxx = len;
            }
        }
    }

    return maxx;
}

int main() {
    init();
    string s;
    getline(cin, s);
    cout << longestPalindromeSubstring(s) << endl; 
    return 0;
}
