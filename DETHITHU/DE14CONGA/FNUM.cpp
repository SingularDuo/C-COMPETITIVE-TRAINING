#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

ll fnum(ll n, ll cnt){
    ll res = 0;
    while(n > 0){
        res += n % 10;
        n /= 10;
    }

    if(res < 10){
        return res; 
    }
    else{
        cnt++;
        return fnum(res, cnt);  
    }
}

ll giaithua(ll n){
    if(n == 1 || n == 0) return 1;  
    return n * giaithua(n - 1);  
}

void sol_brute(vector<ll>& a){  // n <= 20
    ll res = 0;
    for(int i = 0; i < a.size(); i++){
        ll curr = giaithua(a[i]);
        cout<<fnum(curr, 0)<<endl;
    }
    return;
}

signed main() {
    ll t;
    cin >> t;
    vector<ll> a(t);
    ll maxx = INT_MIN;
    for(int i = 0; i < t; i++){
        cin >> a[i];
        maxx = max(maxx, a[i]);
    }
    if(maxx <= 20){
        sol_brute(a);
    }
    return 0;
}
