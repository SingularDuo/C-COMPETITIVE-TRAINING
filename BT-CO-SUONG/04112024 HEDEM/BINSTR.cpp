#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init(){
    freopen("BINSTR.inp", "r", stdin);
    freopen("BINSTR.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main(){
    init();
    int n;
    cin>>n;
    if(n == 1){
        cout<<"2";
        return 0;
    }
    if(n == 2){
        cout<<"3";
        return 0;
    }
    vector<ll> dp(n+1, 0);
    dp[1] = 2;
    dp[2] = 3;
    for(int i = 3; i <= n; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    cout<<dp[n];
}