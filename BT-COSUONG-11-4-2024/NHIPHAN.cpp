#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init(){
    freopen("NHIPHAN.inp", "r", stdin);
    freopen("NHIPHAN.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main(){
    init();
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> vec;
        while (n > 0) {
            ll a = n % 2;
            vec.push_back(a);
            n /= 2;
        }
        vector<ll> luuso;
        for(ll i = vec.size() - 1; i >= 0; i--) {
            if(vec[i] == 1) luuso.push_back(i);
        }
        sort(luuso.begin(), luuso.end());
        for(ll i = 0; i < luuso.size();i++){
            cout<<luuso[i]<<" ";
        }
    }
}