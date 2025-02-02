#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
// author: Phat
// github: SingularDuo
ll kadane(vector<ll>& a){
    ll res = a[0], maxend = a[0];
    for(int i = 1; i < a.size(); i++){
        maxend = max(a[i], maxend + a[i]);
        res = max(res,maxend);
    }
    return res;
}
void sol(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<kadane(a);
    return;
}
signed main() {
    sol();
 
    return 0;
}