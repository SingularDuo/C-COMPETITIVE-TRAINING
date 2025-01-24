#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main(){
    ll n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin>>a[i];
    sort(a.begin(), a.end());
    // trau O(n^2)
    ll cnt = 0;
    vector<int> f(n, 0);
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            ll maxx = max(a[i], a[j]);
            ll minn = min(a[i], a[j]);
            if(maxx - minn <= k && i != j && f[i] == 0 && f[j] == 0){
                cnt++;
                f[i] = 1;
                f[j] = 1;
                continue;
            }
        }
    }
    cout<<cnt;
}