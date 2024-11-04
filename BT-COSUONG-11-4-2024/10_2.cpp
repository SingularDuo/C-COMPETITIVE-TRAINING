#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
/**void init(){
    freopen("10_2.inp", "r", stdin);
    freopen("10_2.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}*/
int main() {
    //init();
    ll n;
    cin >> n;
    vector<ll> vec;
    while (n > 0) {
        ll a = n % 2;
        vec.push_back(a);
        n /= 2;
    }
    for (ll i = vec.size() - 1; i >= 0; i--) {
        cout << vec[i];
    }
    cout << endl;  
    return 0;
}
