#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

int n, k;
vector<int> current;
vector<vector<int>> ans;
vector<int> dp;

bool check(const vector<int>& a) {
    for (int i = 0; i < n; i++) {
        if (abs(a[i] - (i + 1)) > k) return false;
    }
    return true;
}


void gen(int idx) {
    if (idx == n) {  
        if (check(current)) {
            ans.push_back(current);
        }
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (find(current.begin(), current.end(), i) == current.end()) {
            current.push_back(i);
            gen(idx + 1);
            current.pop_back();
        }
    }
}

int factorial(int x) {
    int res = 1;
    for (int i = 1; i <= x; i++) res = (res * i) % MOD;
    return res;
}

int C(int a, int b) {
    if (b > a || b < 0) return 0;
    return (factorial(a) / (factorial(b) * factorial(a - b))) % MOD;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> k;

    if (n <= 8) {
        gen(0);
        cout << ans.size() << endl;
        return 0;
    }

    if (k == 1) {
        if (n == 1) {
            cout << 1 << endl;
            return 0;
        }
        if (n == 2) {
            cout << 2 << endl;
            return 0;
        }
        int prev1 = 1, prev2 = 2, res = 0;
        for (int i = 3; i <= n; i++) {
            res = (prev1 + prev2) % MOD;
            prev1 = prev2;
            prev2 = res;
        }
        cout << prev2 << endl;
        return 0;
    }
    //sub3
    dp.assign(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = max(1LL, i - k); j <= i; j++) {
            dp[i] = (dp[i] + dp[j - 1] * C(i - 1, j - 1)) % MOD;
        }
    }

    cout << dp[n] << endl;
    return 0;
}
