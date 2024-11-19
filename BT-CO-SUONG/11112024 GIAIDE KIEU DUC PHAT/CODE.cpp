#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init(){
    freopen("CODE.inp", "r", stdin);
    freopen("CODE.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main() {
    init();
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll maxx = 0;
    for (int i = 0; i < n ; i++) { 
        ll need = a[i] + 1;
        if (a[i + 1] != need) {
            maxx = max(need, maxx);
        }
    }
    cout << maxx << endl; 
    return 0;
}
