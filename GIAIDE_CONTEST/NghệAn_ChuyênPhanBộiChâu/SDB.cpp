#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define endl "\n"

const int maxn = 1e6;
vector<int> uoc(maxn + 5, 0);
vector<ll> preprocessed(maxn+5, 0);

void Sang_so_luong_uoc() {
    for(int i = 1; i <= maxn; ++i) {
        for (int j = i; j <= maxn; j += i) {
            uoc[j]++;
        }
    }
}

void precompute() {
    for (int i = 1; i <= maxn; i++) {
        preprocessed[i] = preprocessed[i-1] + (uoc[i] == 4);
    }
}ss
void sol() {
    int l, r; cin >> l >> r;
    cout << preprocessed[r] - preprocessed[l-1] << endl;
}

signed main() {
    Sang_so_luong_uoc();
    precompute();
    int t; cin >> t;
    while (t--) {
        sol();
    }
}
