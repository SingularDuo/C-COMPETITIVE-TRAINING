#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int maxn = 1e6;
bool isprime[maxn+2];
void init(){
    freopen("SONT_DOIXUNG.INP", "r", stdin);
    freopen("SONT_DOIXUNG.OUT.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void sieve(){
    for(int i = 1; i <= maxn; i++)isprime[i] = true;
    isprime[0] = isprime[1]= false;
    for(int i = 2; i*i <= maxn; i++){
        if(isprime[i] == true){
            for(int j = i*i; j <= maxn; j+=i){
                isprime[j] = false;
            }
        }
    }
}
bool ispalin(ll n){
    string s1 = to_string(n);
    string s2 = to_string(n);
    reverse(s1.begin(), s1.end());
    return s1 == s2;
}
int main(){
    sieve();
    ll a, b;
    cin>>a>>b;
    ll res = 0;
    for(int i = a; i <= b; i++){
        if(ispalin(i) && isprime[i])res++;
    }
    cout<<res;
}