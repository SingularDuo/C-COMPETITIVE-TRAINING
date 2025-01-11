#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

void init() {
    freopen("BAI4.INP", "r", stdin);
    freopen("BAI4.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

string cong(string a, string b) {
    ll len_a = a.size();
    ll len_b = b.size();
    ll len = max(len_a, len_b);
    vector<int> res(len + 1, 0);
    ll carry = 0;

    while (a.size() < len) a = "0" + a;
    while (b.size() < len) b = "0" + b;

    for (ll i = len - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        res[i + 1] = sum % 10;
        carry = sum / 10;
    }
    res[0] = carry;

    string result = "";
    bool leading_zero = true;
    for (int i = 0; i <= len; i++) {
        if (res[i] == 0 && leading_zero) continue;
        leading_zero = false;
        result += (res[i] + '0');
    }
    if (leading_zero) result = "0";
    return result;
}

int main() {
    //init();
    int n, m;
    cin >> n >> m;
    vector<vector<string>> a(n + 1, vector<string>(n + 1, "1"));
    vector<vector<string>> f(n + 1, vector<string>(n + 1, "0"));


    for (int i = 1; i <= m; i++) {
        int a1, b;
        cin >> a1 >> b;
        a[a1][b] = "0"; 
    }
    f[1][1] = a[1][1]; 

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == "0") {
                f[i][j] = "0"; 
            } else {
                if (i > 1) f[i][j] = cong(f[i][j], f[i - 1][j]);
                if (j > 1) f[i][j] = cong(f[i][j], f[i][j - 1]);
            }
        }
    }

    cout << f[n][n] << endl;

    return 0;
}
