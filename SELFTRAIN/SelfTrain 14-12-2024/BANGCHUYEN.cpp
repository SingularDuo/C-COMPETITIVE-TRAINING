#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init() {
    freopen("BANGCHUYEN.INP", "r", stdin);
    freopen("BANGCHUYEN.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}
int main(){
    //init();
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    ll pair = 0;
    if(n > k){
        if(n % k == 0) pair = n / k;
        else pair = n / k + 1;
    }
    else{
        sort(a.begin(), a.end(), greater<ll>());
        cout << a[0];
        return 0;
    }
    ll div = pair;
    ll res = INT_MIN;  
    vector<ll> temp;
    for(ll i = 0; i < n; i++){
        if(div > 0){
            temp.push_back(a[i]);
            div--;
        }
        if(div == 0){
            ll curr = 0;
            for(ll j = 0; j < temp.size(); j++)
                curr += temp[j];
                res = max(curr, res);
                div = pair;
                temp.clear();
        }
    }
    cout << res;
}
