#include <bits/stdc++.h>
using namespace std;

bool isprime(long long n){
    if(n<=1) return false;
    if(n==2 || n==3) return true;
    if(n%2==0 || n%3==0) return false;
    for(long long i=5; i*i<=n; i++){
        if(n%i==0 || n%(i+2)==0) return false;
    }
    return true;
}
void sol(){
    long long n;
    cin>>n;
    if(isprime(n)){
        cout<<"YES"<<'\n';
    }else{
        cout<<"NO"<<'\n';
    }
}
int main(){
    sol();
    return 0;
}
