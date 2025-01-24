#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll nen(ll n) {
    ll cnt = 0;
    ll i = 2; 
    while (n > 2) {
        if (n % i != 0) {
            n = i; 
            i = 2; 
            cnt++;
        } else {
            i++;                    
        }
    }
    return cnt;
}

int main() {
    ll a, b;
    cin>>a>>b;
    ll cnt = 0;
    for (ll i = a; i <= b; i++) {
        cnt+=nen(i);
    }
    cout<<cnt;
    return 0;
}
