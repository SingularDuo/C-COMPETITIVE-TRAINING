#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init(){
    freopen("BINENUM.inp", "r", stdin);
    freopen("BINENUM.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main() {
    ll n, k;
    cin >> n >> k;
    for (ll i = 1; i <= n; i++) {
        if (__builtin_popcount(i) == k) {
            cout << i << " ";
        }
    }
    return 0;
}
