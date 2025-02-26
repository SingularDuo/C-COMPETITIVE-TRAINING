#include <bits/stdc++.h>
using namespace std;
#define ll long long

void init() {
    freopen("FWORD1.inp", "r", stdin);
    freopen("FWORD1.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n, m, k, x;
string s;
vector<ll> fill_pos;
vector<string> to_fill;
vector<ll> cnt;
vector<char> res;

void sol() {
    cin >> n >> m >> k >> x;
    cin >> s;

    fill_pos.clear();
    cnt.assign(m, 1);
    to_fill.resize(m);

    for (int i = 0; i < m; i++) cin >> to_fill[i];

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '#') fill_pos.push_back(i);
    }

    ll temp_x = x - 1;
    for (ll i = m - 1; i >= 0; i--) {
        cnt[i] = temp_x % k;
        temp_x /= k;
    }

    res.resize(m);
    for (ll i = 0; i < m; i++) {
        sort(to_fill[i].begin(), to_fill[i].end());
        res[i] = to_fill[i][cnt[i]];
    }

    for (ll i = 0; i < fill_pos.size(); i++) {
        s[fill_pos[i]] = res[i];
    }

    cout << s;
}

int main() {
    init();
    sol();
}
