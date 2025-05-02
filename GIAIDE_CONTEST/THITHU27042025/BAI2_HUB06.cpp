#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl "\n"
void init()
{
    freopen("BAI2_HUB06.inp", "r", stdin);
    freopen("BAI2_HUB06.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
bool ispalin(string &s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++, r--;
    }
    return true;
}

signed main() {
    init();
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dp(n + 1, 0); 
    dp[0] = 1; // chuoi 0 thi chi co 1 cach duy nhat la d cat gi thi ms dc
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (ispalin(s, j, i - 1)) {
                dp[i] += dp[j]; 
            }
        }
    }

    cout << dp[n] << endl; 
}
