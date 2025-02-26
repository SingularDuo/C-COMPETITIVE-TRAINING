#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main(){
    ll k, r, m;
    cin >> k >> r >> m;
    vector<pair<ll, ll>> a(m + 1);
    for(int i = 1; i <= m; i++){
        cin >> a[i].first >> a[i].second;
    }
    ll n;
    cin >> n;
    vector<pair<ll, ll>> diachi(n +1);
    vector<ll> songuoi(n+1);
    for(int i = 1; i <= n; i++){
        cin>>diachi[i].first>>diachi[i].second>>songuoi[i];
    }
    int cnt = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n;j++){
            if(diachi[j].first <= a[i].first + r && diachi[j].second <= a[i].second +r ){
                cnt += songuoi[j];
            }
            else if(diachi[j] . first >= a[i].first - r && diachi[j].second >= a[i].second - r){
                cnt+= songuoi[j];
            }
        }
    }
    cout<<cnt;
}
