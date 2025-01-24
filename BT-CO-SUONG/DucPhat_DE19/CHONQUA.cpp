#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

void init() {
    freopen("CHONQUA.INP", "r", stdin);
    freopen("CHONQUA.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    init();
    ll d, r, k;
    cin >> d >> r >> k;
    k -=2;
    vector<vector<ll>> a(d + 1, vector<ll>(r + 1, 0)); 

    for (int i = 1; i <= d; i++) {
        for (int j = 1; j <= r; j++) {
            char s;
            cin >> s;
            if (s == '.') {
                a[i][j] = 0;
            } else if (s == '*') {
                a[i][j] = 1;
            }
        }
    }


    vector<vector<ll>> f(d + 1, vector<ll>(r + 1, 0));
    for (int i = 1; i <= d; i++) {
        for (int j = 1; j <= r; j++) {
            f[i][j] = f[i][j - 1] + f[i - 1][j] - f[i - 1][j - 1] + a[i][j];
        }
    }

    ll maxx = LLONG_MIN;
    for (int i = 1; i <= d - k + 1; i++) {
        for (int j = 1; j <= r - k + 1; j++) {
            ll current = f[i + k - 1][j + k - 1] - f[i - 1][j + k - 1] - f[i + k - 1][j - 1] + f[i - 1][j - 1];
            maxx = max(current, maxx);
        }
    }
    cout << maxx;

    return 0;
}
