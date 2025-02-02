#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void init() {
    freopen("DIVSEQ.inp", "r", stdin);
    freopen("DIVSEQ.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    //init();
        ll n, k;
        cin >> k >> n;
        vector<ll> a(n + 1);
        for (ll i = 1; i <= n; i++) cin >> a[i];
        vector<ll> prefix(n + 1);
        prefix[0] = 0;
        map<ll, ll> cnt;
        for (ll i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + a[i];
            cnt[prefix[i] % k]++;
        }
        cnt[0]++;
        // 0 % k du
        ll soluong = 0;
        for (auto i : cnt) {
            if(i.second > 1){
                soluong += (i.second * (i.second - 1)) / 2;
            }
        }
        cout << soluong << endl;

    return 0;
}