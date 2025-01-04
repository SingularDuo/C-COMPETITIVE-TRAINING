#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main(){
    ll n;
    cin>>n;
    if(n % 10 == 0){
        cout<<n;
        return 0;
    }
    ll endnum = n % 10;

    if(endnum <= 5){
        cout<<n - endnum;
    }
    if(endnum > 5){
        cout<<n + (10-endnum);
    }
    return 0;
}