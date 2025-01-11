#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

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
    ll cnt = 0;
    for (ll i = 1; i <= 50; i++) {
        cout<<i<<" "<<nen(i)<<endl;
    }
    return 0;
}
