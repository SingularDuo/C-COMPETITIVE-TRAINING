#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
bool check_scp(ll n){
    ll a = sqrt(n);
    return a*a == n;
}
bool near_scp(ll n){
    if(check_scp(n+1) || check_scp(n-1)) return true;
    else return false;
}
int main(){
    ll n;
    cin>>n;
    int a[n+1][n+1];
    vector<pair<ll, ll>> b(n+1);
    for(int i = 1; i <= n;i++){
        for(int j = 1; j <= n; j++){
            cin>>a[i][j];
            if(near_scp(a[i][j])){
                b.push_back({i, j});
            }
        }
    }
    

}
/*
3 5
+5
8 10
+7
15 17
+9
24 26
+11
35 37
*/