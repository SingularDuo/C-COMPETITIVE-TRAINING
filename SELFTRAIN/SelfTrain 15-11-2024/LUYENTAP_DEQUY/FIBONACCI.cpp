#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
long long fibo(ll n){
    if(n == 0 || n == 1){
        return n;
    }
    else return fibo(n-1) + fibo(n-2);
}
int main(){
    ll n;
    cin>>n;
    cout<<fibo(n);
    return 0;
}