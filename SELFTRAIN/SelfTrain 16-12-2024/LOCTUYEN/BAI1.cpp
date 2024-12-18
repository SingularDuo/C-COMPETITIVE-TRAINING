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
ll tonguoc(ll n){
    ll tong = 0;
    for(int i = 1; i <= sqrt(n); i++){
        if(n % i == 0) tong += i;
        if(i != n/i)tong += n/i;
    }
    return tong;
}
int main(){
    ll n;
    cin>>n;
    cout<<tonguoc(n);
}