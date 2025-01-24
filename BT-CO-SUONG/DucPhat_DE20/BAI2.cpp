#include<bits/stdc++.h>
using namespace std;
void init(){
    freopen("BAI2.INP", "r", stdin);
    freopen("BAI2.OUT", "w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main(){
    init();
    long long n, k;
    cin>>n>>k;
    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    cout<<a[k];
}