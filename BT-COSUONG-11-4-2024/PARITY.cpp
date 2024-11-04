#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init(){
    freopen("PARITY.inp", "r", stdin);
    freopen("PARITY.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main() {
    init();
    int t;
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
        ll cnt = 0;
        for (ll i = vec.size() - 1; i >= 0; i--) {
            if(vec[i] == 1) cnt++;
        }
        if( cnt % 2 == 0) cout<<"even"<<endl; 
        if( cnt % 2 != 0) cout<<"odd"<<endl; 
    }
    
    return 0;
}
