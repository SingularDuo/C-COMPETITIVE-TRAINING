#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init(){
    freopen("BAI3.INP", "r", stdin);
    freopen("BAI3.OUT", "w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void bruteforce(ll n, ll k){
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin>>a[i];
    sort(a.begin(), a.end());
    // trau O(n^2) ==> n <= 1e4
    ll cnt = 0;
    vector<int> f(n, 0);
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            ll maxx = max(a[i], a[j]);
            ll minn = min(a[i], a[j]);
            if(maxx - minn <= k && i != j && f[i] == 0 && f[j] == 0){
                cnt++;
                f[i] = 1;
                f[j] = 1;
                continue;
            }
        }
    }
    cout<<cnt;
    return;
}
void optimize(ll n, ll k){
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin>>a[i];
    sort(a.begin(), a.end());

}
int main(){
    init();
    ll n, k;
    cin>>n>>k;
    if(n <= 1e3){
        bruteforce(n, k);
    }
}
/*
logic can tim cac cap so co hieu ( so lon - so be) <= k va chua duoc su dung bat cu lan nao truoc do
1. Lam sao de tim cac cap do?
=> co the su dung map de vua luu gia tri vua dem hoac su dung mang danh dau

*/