#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main(){
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