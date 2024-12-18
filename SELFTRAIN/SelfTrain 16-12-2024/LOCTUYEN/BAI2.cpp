#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int maxn = 1e6;

void init(){
    freopen("BAI1.INP", "r", stdin);
    freopen("BAI1.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int isprime[maxn+2]; 

void sang(){
    for(int i = 0; i <= maxn; i++){
        isprime[i] = 1;
    }
    isprime[0] = isprime[1] = 0;
    for(int i = 2; i * i <= maxn; i++){
        if(isprime[i]){
            for(int j = i * i; j <= maxn; j += i){
                isprime[j] = 0;
            }
        }
    }
}

bool check(ll n, ll x){
    vector<ll> a;
    vector<ll> b;
    for(int i = 2; i <= max(n, x); i++){
        if(isprime[i]){
            if(n % i == 0) a.push_back(i);
            if(x % i == 0) b.push_back(i);
        }
    }
    return (a == b);
}

int main(){
    //init();
    sang();
    ll l, r;
    cin>>l>>r;
    ll res = 0;
    for(ll i = l; i <= r; i++){
        for(ll j = i+1; j <= r; j++){
            if(check(i, j)){
                cout<<i<<" "<<j<<endl;
                res++;
            }
        }
    }
    cout<<res<<endl;
}
