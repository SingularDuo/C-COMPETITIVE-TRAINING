#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl "\n"
const int MOD = 1e9 + 7;

void init() {
    freopen("SECRCD.inp", "r", stdin);
    freopen("SECRCD.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

vector<pair<int, int>> pttsnt(int n) {
    vector<pair<int, int>> res;
    int count = 0;
    while (n % 2 == 0) {
        count++;
        n /= 2;
    }
    if (count > 0) res.push_back({2, count});
    for (int i = 3; i * i <= n; i += 2) {
        count = 0;
        while (n % i == 0) {
            count++;
            n /= i;
        }
        if (count > 0) res.push_back({i, count});
    }
    if (n > 1) res.push_back({n, 1});
    return res;
}

signed main() {
    init();
    int n;
    cin >> n;
    vector<ll> a(n);
    ll calc_s = 1;
    bool ok = true, all_prime = true;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (calc_s <= 1e12 / a[i]) calc_s *= a[i];
        else ok = false;
        if (!is_prime(a[i])) all_prime = false;
    }

    if (calc_s <= 1e12 && ok) {  // sub1
        vector<pair<int, int>> sub1 = pttsnt(calc_s);
        ll res = 1;
        for (auto& i : sub1) {
            res *= (i.second + 1);
        }
        cout << res;
        return 0;
    }

    if (n <= 1000 && all_prime) {  // sub2
        cout << (1LL << n);
        return 0;
    }

    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        vector<pair<ll, ll>> current = pttsnt(a[i]);
        for (auto& j : current) {
            cnt[j.first] += j.second;
        }
    }

    ll res = 1;
    for (auto i : cnt) {
        res = (res * (i.second + 1)) % MOD;
    }
    cout << res % MOD;
}
