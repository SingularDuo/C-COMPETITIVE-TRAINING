#include<bits/stdc++.h>
using namespace std;
int LCS(const string& s1, const string& s2) {
    int n = s1.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));


    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; ++)
        {
            if (s1[i - 1] == s2[j - 1])dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][n];
}

int LPS(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    return LCS(s, rev);
}

int main() {
    int n; cin>>n;

    string s;
    cin >> s;

    int lps = LPS(s);
    cout<<(int)s.size() - lps;

    return 0;
}
