#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long

int LCS(const string& s1, const string& s2) {
    int n = s1.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
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

bool ispalin(string s) {
    string sub = s;
    reverse(sub.begin(), sub.end());
    return sub == s;
}

bool sliding_window(string s, int win) {
    int ans = LLONG_MIN, n = s.size();
    for(int i = 0; i <= n - win; i++) {
        string current = "";
        for(int j = 0; j < win; j++) {
            current += s[i + j];
        }
        if(ispalin(current)) return true;
    }
    return false;
}

string update(const string& s) {
    if (s.empty()) return "^$";
    string result = "^";
    for (char c : s) {
        result += "#" + string(1, c);
    }
    result += "#$";
    return result;
}

int manacher(const string& s) {
    string t = update(s);
    int n = (int)t.size();
    vector<int> p(n, 0);
    int maxLen = 0;
    for (int i = 1; i < n - 1; i++) {
        while (t[i + 1 + p[i]] == t[i - 1 - p[i]]) {
            p[i]++;
        }
        maxLen = max(maxLen, p[i]);
    }
    return maxLen;
}



signed main() {
    string s;
    cin >> s;
    int n = s.size();
    /*for(int i = n; i >= 1; i--) {
        if(sliding_window(s, i)) {
            cout << i << endl;
            break;
        }
    }*/
    cout << manacher(s) << endl;
    int lps = LPS(s);
    cout << lps;

    return 0;
}
