#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)cin>>a[i];
    vector<ll> dpsau(n, 0);
    vector<ll> dptruoc(n, 0);
    // dp[i] la gia tri lon nhat cua day con lien tiep den vi tri i
    dp[0] = a[0];
    for(int i = 0; i < n; i++){
        dpsau[i] = max(a[i], a[i] + dpsau[i-1]);
        dptruoc[i] = max(a[i], a[i] + dptruocP[i+1]);
    }

}