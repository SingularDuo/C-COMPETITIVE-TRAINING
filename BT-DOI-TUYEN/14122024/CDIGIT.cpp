#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main(){
    ll n;
    cin>>n;
    ll res = 0;
    ll d100 = 192;
    ll d1000 = 2893;
    ll d10000 = 38894;
    ll d100k  = 488895;
    ll d1m = 5888896;
    if(n >= 1000 && n <= 10000){
        res = d1000;
        for(ll i = 1001;i<=n;i++){
           string s = to_string(i);
            int a = (int)s.size();
            res+=a; 
        }
        cout<<res;
        return 0;
    }
    if(n >= 10000 && n <= 100000){
        res = d10000;
        for(ll i = 10001;i<=n;i++){
           string s = to_string(i);
            int a = (int)s.size();
            res+=a; 
        }
        cout<<res;
        return 0;
    }
    if(n >= 100000 && n <= 1000000){
        res = d10000;
        for(ll i = 10001;i<=n;i++){
           string s = to_string(i);
            int a = (int)s.size();
            res+=a; 
        }
        cout<<res;
        return 0;
    }
    if(n >= 1000000){
        res = d10000;
        for(ll i = 10001;i<=n;i++){
           string s = to_string(i);
            int a = (int)s.size();
            res+=a; 
        }
        cout<<res;
        return 0;
    }
    for(ll i = 1;i<=n;i++){
           string s = to_string(i);
            int a = (int)s.size();
            res+=a; 
        }
        cout<<res;
    return 0;
}