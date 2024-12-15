#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init(){
    freopen("TBC.inp", "r", stdin);
    freopen("TBC.out","w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main(){
    init();
    int n;
    cin>>n;
    vector<ll> a(n+2);
    for(int i = 1; i <= n;i++)cin>>a[i];
    vector<ll> b(n+2);
    ll psum = 0; // ll = 2*10^18
    for(ll i = 1; i <= n; i++){
        b[i] = a[i]*i - psum;
        psum += b[i];
        //cout<<psum<<endl;
    }
    for(ll i = 1; i <= n; i++)cout<<b[i]<<" ";
}