#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main(){
    ll n;
    cin>>n;
    ll s1 = 1, cnt = 0;
    while(n >= s1){
        cnt++;
        s1++;
    }
    cout<<cnt;
}