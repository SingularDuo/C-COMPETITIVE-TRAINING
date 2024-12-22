#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const ll maxn = 1e5;
vector<ll> a(maxn+2, 0);
vector<ll> f(maxn+2, 0);
void init(){
    freopen("BAI2.INP", "r", stdin);
    freopen("BAI2.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void cap3(){
    for(ll i = 1; i <= maxn; i *= 3){
        f[i] = 1;
    }
}
int main(){
    ll n;
    cin>>n;
    for(ll i =1; i <= n; i++){
        cin>>a[i];
    }
    if(n <= 1e3){
        ll res = 0;
        for(ll i = 1; i <= n; i++){
            for(ll j = i+1; j <= n; j++){
                if((a[i] + a[j]) % 3 == 0){
                    res++;
                }
            }
        }
        cout<<res;
        return 0;
    }
}