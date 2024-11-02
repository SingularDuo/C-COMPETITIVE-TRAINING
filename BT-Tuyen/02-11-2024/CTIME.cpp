#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main(){
    int n;
    cin>>n;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) cin>>a[i].first>>a[i].second;
    vector<int> luu(1e6 +5, 0);
    for(int i = 0; i < n; i++)
    {
        for(int j = a[i].first; j <= a[i].second; j++){
            luu[j] = 1;
        }
    }
    ll maxx = 0;
    ll minn = INT_MAX;
    for(int i = 0; i < n; i++){
        ll curr  = max(a[i].first, a[i].second);
        ll currmin = min(a[i].first, a[i].second);
        maxx = max(curr, maxx);
        minn = min(currmin,minn);
    }
    vector<int> luukolam(1e6+5, 0);
    for(int i = minn; i < maxx; i++){
        if(luu[i] == 0){
            ll max0 = 0;
            for(int j = i; j <= maxx; j++){
                if(luu[j] == 1){
                    max0 = j- 1;
                    break;
                }
            }
            //cout<<max0<<" "<<i<<endl;
            ll c = max0 - i+2;
            luukolam.push_back(c);
            if( c == 101){
                cout<<i<<" "<<max0<<endl;
            }
        }
    }
    sort(luukolam.begin(), luukolam.end(), greater<int>());
    cout<<luukolam[0];
}