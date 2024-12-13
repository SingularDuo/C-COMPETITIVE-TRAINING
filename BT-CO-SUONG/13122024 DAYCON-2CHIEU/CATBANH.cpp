#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
ll a[1005][1005];
ll f[1005][1005];
void init(){
    freopen("CATBANH.INP", "r", stdin);
    freopen("CATBANH.OUT", "w", stdout);
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
    ll maxx = LLONG_MIN;
    for(ll i = 1; i <= n - k + 1; i++){
        for(ll j = 1; j <= n - k + 1; j++){
            ll currval = a[i][j];
            for(ll x = 0; x < k; x++){
                for(ll y = 0; y <= x; y++){
                    currval += a[i + x][j + y];
                }
            }
            maxx = max(maxx, currval);
        }
    }
    cout << maxx;
}
