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

void createLCM() {
    ll last = 1;
    for (int i = 1; i <= 42; i++) {
        lcmv[i] = lcm(last, i);
        last = lcmv[i];
    }
}
void calculate_g(int R) {
    for (int i = 1; i <= 42; i++) {
        g[i] = R / lcmv[i];
    }
}
void calculate_f(int R) {
    for (int i = 2; i <= 42; i++) {
        f[i] = g[i-1] - g[i];
    }
}
ll OneToR(int L, int R) {
    ll cnt = 0;
    for (int i = 2; i <= 42; i++) {
        ll fi = f[i];
        cnt += fi * (nen(i) + 1); 
    }
    return cnt;
}

int main() {
    int L = 3; 
    int R = 7;

    createLCM();      
    calculate_g(R);  
    calculate_f(R);    

    ll result = OneToR(L, R); 
    cout << result << endl;

    return 0;
}