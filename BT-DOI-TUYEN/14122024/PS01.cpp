#include<bits/stdc++.h>
#include<numeric>
using namespace std;
#define ll long long
#define endl "\n"
int main(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll x = lcm(b, d); 
    a *= x / b; 
    c *= x / d; 
    ll ans = a - c; 
    ll l = __gcd(abs(ans), x); 
    ans /= l; 
    x /= l;
    cout << ans << " " << x << endl;
}
