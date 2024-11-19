#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init() {
    freopen("BAI3.inp", "r", stdin);
    freopen("BAI3.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main(){
    init();
    ll n;
    cin>>n;
    vector<ll> a(n);
    map<int, int> counts;
    for(int i = 0; i < n;i++){
        cin>>a[i];
        counts[a[i]]++;
    }
    int cnt = 0;
    int cntnhomkhac = 0;
    for(auto i : counts){
        if(i.second != 1)cnt++;
        else cntnhomkhac++;
    }
    if(cntnhomkhac != 0)cnt++;
    cout<<cnt;
}