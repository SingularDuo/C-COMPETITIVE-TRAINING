#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
ll a[1005][1005];
ll f[1005][1005];
void init(){
    freopen("CHUX.INP", "r", stdin);
    freopen("CHUX.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main(){
    init();
    ll n, k;
    cin >> n >> k;
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    for(ll i = 1;i <= n;i++){
        for(ll j = 1; j <= n; j++){
            f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + a[i][j];
        }
    }
    ll maxx = INT_MIN;
    for(ll i = k - 1; i <= n - k + 2; i++){
        for(ll j = k - 1; j <= n - k + 2; j++){
            ll sum = f[i][j] - f[i-k][j] - f[i][j-k] + f[i-k][j-k];
            ll f_center = i - k, s_center = j - k;
        }
    }
    cout << maxx;
}
