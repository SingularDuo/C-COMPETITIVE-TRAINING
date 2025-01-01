#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
ll laycaidau(ll n){
    ll dau = 0;
    while(n >= 1){
        dau = n % 10;
        n /=10;
    }
    return dau;
}
int main(){
    ll n;
    cin>>n;
    vector<ll> a(n+1);
    for(int i = 1; i <= n; i++)cin>>a[i];
    ll maxx = 9;
    string s1 ="";
    for(int i = 1; i <= n; i++){
        if(laycaidau(a[i]) == maxx){
            for(int j = i; j<= n; j++){
                if(laycaidau(a[j]) == maxx){
                    cout<<a[j];
                }
            }
        }
        maxx--;
    }
    cout<<s1;
        
    
}