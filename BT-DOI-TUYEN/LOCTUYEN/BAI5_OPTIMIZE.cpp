#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

vector<ll> lcmv(43);
vector<ll> f(43);
vector<ll> g(43);

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

void createlCM() {
    ll last = 1;
    for (ll i = 1; i <= 42; i++) {
        lcmv[i] = lcm(last, i);
        last = lcmv[i];
    }
}

void calculate_g(ll r) {
    for (ll i = 1; i <= 42; i++) {
        g[i] = r / lcmv[i];
    }
}

void calculate_f(ll r) {
    for (ll i = 1; i <= 42; i++) {
        f[i] = g[i - 1] - g[i];
    }
}

ll OneToX(ll x) {
    ll cnt = 0;
    for (ll i = 2; i <= 42; i++) {
        ll fi = f[i];
        cnt += fi * (nen(i) + 1); 
    }
    return cnt;
}

int main() {
    ll l, r;
    cin>>l>>r;   
    createlCM();      
    calculate_g(r);
    calculate_f(r);
    ll cnt_r = OneToX(r);
    if (l > 1) {
        calculate_g(l - 1);
        calculate_f(l - 1);
    }
    ll cnt_l_minus_1 = 0;
    if (l > 1) {
        cnt_l_minus_1 = OneToX(l - 1);
    }
    ll result = cnt_r - cnt_l_minus_1;
    cout << result << endl;

    return 0;
}
