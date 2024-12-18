#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "/n"
void sobe(ll n, ll m){
    ll a[n+1];
    for(ll i = 1; i <= n; i++)cin>>a[i];
    ll maxx = 0;
    for(ll i = 1; i <= n; i++){
        ll need = m - a[i];
        for(ll j = 1; j <= n; j++){
            for(ll k = 1; k <= n; k++){
                if(i != j && j != k && k != i){
                    if(a[i]+a[j]+a[k] <= m){
                        maxx = max(maxx, a[i]+a[j]+a[k]);
                    }
                }
            }
        }
    }
    cout<<maxx;
    return;
}
int main(){
    ll n, m;
    cin>>n>>m;
    if(n <= 900){
        sobe(n,m);
        return 0;
    }
    vector<ll> a(n+1);
    vector<ll> f(500000, 0);
    for(ll i = 1; i<= n; i++){
        cin>>a[i];
        f[a[i]]++;
    }
    ll maxx = LLONG_MIN;
    for(ll i = 1; i<= n;i++){
        ll need = m - a[i];
        for(ll j = 1; j <= need; j++){
            if(f[j] >= 1){
                auto it = find(a.begin(), a.end(), j);
                ll need2 = m - a[i] - a[distance(a.begin(),it)];
                auto it2 = find(a.begin(),a.end(), need2);
                if(a[i] + a[distance(a.begin(), it)] + a[distance(a.begin(),it2)] <= m){
                    maxx = max(maxx,a[i] + a[distance(a.begin(), it)] + a[distance(a.begin(),it2)] );
                }
            }
        }
    }
    cout<<maxx;
}