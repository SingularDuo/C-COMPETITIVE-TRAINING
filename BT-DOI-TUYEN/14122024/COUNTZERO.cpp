#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
int main() {
    ll n;
    cin >> n;
    ll i = 1;
    ll res = 0;
    while(n / power(5, i) > 0){
        res += n/power(5,i);
        i++;
    }
    cout<<res;
    return 0;
}
