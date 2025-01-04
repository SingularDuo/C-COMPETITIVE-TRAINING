#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

const ll maxn = 1e6;
bool isprime[maxn + 1];
vector<bool> primes;
vector<ll> souocc;
vector<ll> tonguocc;
 
void init() {
    freopen("test.INP", "r", stdin);
    freopen("test.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void sieve(ll maxn) {
    ll nsqrt = sqrt(maxn);
    for (ll i = 2; i <= maxn; i++) isprime[i] = true;
    isprime[0] = isprime[1] = false;
    for (ll i = 2; i <= nsqrt; i++) {
        if (isprime[i]) {
            for (ll j = i * i; j <= maxn; j += i) {
                isprime[j] = false;
            }
        }
    }
}

void sieve_odd(ll maxn) {
    primes.assign(maxn / 2 + 1, true);
    primes[0] = false;
    for (ll i = 1; (2 * i + 1) * (2 * i + 1) <= maxn; i++) {
        ll t = 2 * i + 1;
        if (primes[i]) {
            for (ll j = t * t; j <= maxn; j += t * 2) {
                primes[j / 2] = false;
            }
        }
    }
}

void souoc(ll maxn) {
    souocc.assign(maxn, 0);
    for (ll i = 1; i <= maxn; i++) {
        for (ll j = i; j <= maxn; j += i) {
            souocc[j]++;
        }
    }
}

void tonguoc(ll maxn) {
    tonguocc.assign(maxn, 0);
    for (ll i = 1; i <= maxn; i++) {
        for (ll j = i; j <= maxn; j += i) {
            tonguocc[j] += i;
        }
    
    }
}
vector<ll> uoc;
void uocnngto(ll n){
    uoc.assign(n, LLONG_MAX);
    for(ll i = 0; i <= n; i++){
        for(ll j = 0; j <= n; j+=i){
            ll val = uoc[j];
            uoc[j] = min(val,i);
        }
    }

}
int main(){
    int n;
    cin>>n;
    uocnngto(n);
    cout<<uoc[n];
}

