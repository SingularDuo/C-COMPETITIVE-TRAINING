#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

const int maxn = 1e5;
const int MOD = 1e9 + 7;
bool isprime[maxn + 1];

void sieve() {
    for (int i = 0; i <= maxn; i++) isprime[i] = true;
    isprime[1] = isprime[0] = false;
    for (int i = 2; i * i <= maxn; i++) {
        if (isprime[i]) {
            for (int j = i * i; j <= maxn; j += i) {
                isprime[j] = false;
            }
        }
    }
}
vector<ll> uocnguyentomin(ll n){
    ll i = 2;
    vector<ll>uoc;
    while(n > 1){
        if(n % i == 0 && isprime[i]){
            while(n % i == 0){
                n /= i;
            }
            uoc.push_back(i);
        }
        i++;
    }
    return uoc;
}
bool tuongdong(ll a, ll b){
    vector<ll> uoc1 = uocnguyentomin(a);
    vector<ll>uoc2  = uocnguyentomin(b);
    ll len1 = uoc1.size(), len2 = uoc2.size();
    sort(uoc1.begin(), uoc1.end());
    sort(uoc2.begin(), uoc2.end());
    if(len1 != len2)return false;
    for(int i = 0; i <= uoc1.size()-1; i++){
        if(uoc1[i] != uoc2[i])return false;
    }
    return true;
}
int main(){
    sieve();
    ll a, b;
    cin>>a>>b;
    ll cnt = 0;
    for(int i = a; i <= b; i++){
        for(int j = i+1; j <= b; j++){
            if(tuongdong(i, j))cnt++;
        }
        
    }
    cout<<cnt;
}