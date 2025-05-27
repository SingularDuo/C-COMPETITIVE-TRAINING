#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

void init() {
    freopen("CDIV.inp", "r", stdin);
    freopen("CDIV.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

const int MAXN = 1e6 + 5;
int freq[MAXN];

void cnt(int x) {
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            freq[i]++;
            if (i != x / i) freq[x / i]++;
        }
    }
}

signed main() {
    init();
    int n;
    cin >> n;
    vector<int> a(n);

    for (int& x : a) {
        cin >> x;
        cnt(x);
    }

    int res = 0;
    for (int i = 1; i < MAXN; i++) {
        if (freq[i] >= 2) res = max(res, i);
    }

    cout << res;
    return 0;
}
