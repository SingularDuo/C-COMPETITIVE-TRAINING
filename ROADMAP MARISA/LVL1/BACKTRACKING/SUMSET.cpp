#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void sol(){
    ll n, k;
    cin>>n>>k;
    vector<ll> v(n);
    vector<ll> f(n, 0);
    for(int i=0;i<n;i++) cin>>v[i];
    f[0] = v[0];
    for(int i = 1; i < n; i++){
        f[i] = f[i-1] + v[i];
    }
    for(int l = 0; l < n; l++){
        for(int r = l; r < n; r++){
            ll current = f[r] - f[l-1];
            if(current == k){
                cout<<"YES";
                return;
            }
        }
    }
    cout<<"NO";
    return;
}
signed main() {
    sol();
    return 0;
}