#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
vector<ll> f;
ll ex1(vector<ll>& a, ll idx){
ll sum1 = 0, sum2 = 0;
    sum1 = f[idx-1]-f[0];
    sum2 = f[a.size()-1] - f[idx-1]; // fix: use a.size()-1 instead of a.size()
    ll minn = min(sum1,sum2);
    ll maxx = max(sum1, sum2);
    minn *= -1;
    return maxx + minn;
}
//brute force
void sol(ll n){
    vector<ll> a(n);
    for(int i = 0; i < n; i++)cin>>a[i];
    ll maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        maxi = max(maxi, ex1(a, i));
    }
    f[0]=a[0];
    for(int i = 1; i<n;i++)f[i]=f[i-1]+a[i];
    
    cout<<maxi;
    return;
}
signed main() {
    ll n;
    cin>>n;
    if(n <= 1e4){
        sol(n);
    }
    return 0;
}