#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init(){
    freopen("BAI1.INP", "r", stdin);
    freopen("BAI1.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
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
bool isdacbiet(int n){
    ll res =  0;
    while(n > 0){
        res += n % 10;
        n /= 10;
    }
    return res % 5 == 0;
}
int main(){
    init();
    sieve();
    int t;
    cin>>t;
    while(t--){
        ll a, b;
        cin>>a>>b;
        int res =0;
        for(int i = a; i <= b; i++){
            if(isdacbiet(i) && isprime[i]){
                res++;
            } 
            else continue;
        }
        cout<<res<<endl;
    }
}