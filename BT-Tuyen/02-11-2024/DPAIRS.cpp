#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n, k;
    cin>>n>>k;
    vector<int> vec(n);
    for(ll i = 0; i < n; i++) cin>>vec[i];
    sort(vec.begin(), vec.end(), greater<int>()); 
    int cnt =0;
    map<int, int> dem;
    for(int c : vec)dem[c]++;
    for(ll i = 0; i < n;i++){
        ll current = vec[i] - k;
        cnt += dem[current];
        if(vec[i] == current)cnt--;
        //cout<< dem[current]<<" ";
    }
    cout<<cnt;
}

/**
5 0
1 1 1 2 2 
 */