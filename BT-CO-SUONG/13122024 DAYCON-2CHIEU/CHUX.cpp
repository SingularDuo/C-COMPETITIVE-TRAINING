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
    ll maxx = INT_MIN;
    for(ll i = k - 1; i <= n - k + 2; i++){
        for(ll j = k - 1; j <= n - k + 2; j++){
            ll currval = a[i][j];
            for(ll l = 1; l <= (n-k/2)+2; l++){
                currval += a[i-l][j-l];
                currval += a[i+l][j+l];
                currval += a[i-l][j+l];
                currval += a[i+l][j-l];
            }
            maxx = max(maxx, currval);
        }
    }
    cout << maxx;
}
