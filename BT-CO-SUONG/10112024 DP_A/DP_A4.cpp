#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main(){
    int n;
    cin >> n;
    vector<ll> vec(n);
    for(int i = 1; i < n; i++) cin >> vec[i];
    
    int t;
    cin >> t;
    vector<pair<ll, ll>> luu(t);
    for(int i = 1; i < t; i++) cin >> luu[i].first >> luu[i].second; 
    vector<ll> luugiatri;
    for(int i = 1; i < t; i++){
        ll cnt = 0;
        for(int j = luu[i].first; j <= luu[i].second; j++){
            cout<<vec[j]<<" ";
            cnt += vec[j];

        } 
        cout<<endl;
        cout << cnt << endl;
    }
    return 0;
}
