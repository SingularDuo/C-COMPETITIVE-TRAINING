#include <bits/stdc++.h>
using namespace std;

#define ll long long

void init() {
    freopen("TINHIEU.INP", "r", stdin);
    freopen("TINHIEU.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    init();
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> psum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        psum[i] = psum[i - 1] + a[i];
    }
    unordered_map<int, int> freq;
    freq[0] = 1;
    ll res = 0;

    for (int i = 1; i <= n; i++) {
        int curr_val = psum[i] - i / 2;
        freq[curr_val]++;
    }
    
    return 0;
}
