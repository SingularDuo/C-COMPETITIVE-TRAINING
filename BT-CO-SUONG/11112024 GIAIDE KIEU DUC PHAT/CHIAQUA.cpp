#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init(){
    freopen("CHIAQUA.inp", "r", stdin);
    freopen("CHIAQUA.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main(){
    init();
    ll n;
    cin>>n;
    vector<ll> a(n);
    ll tong = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        tong+=a[i];
    }
    ll final = tong / 2;
    if(final % 100  == 0) cout<<"YES";
    else cout<<"NO";
}