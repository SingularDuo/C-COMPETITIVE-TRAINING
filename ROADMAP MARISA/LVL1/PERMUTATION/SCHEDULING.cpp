#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

ll maxtimecal(vector<pair<ll, ll>>& a){
    ll n = a.size();
    ll maxx = 0;
    ll fillTime = 0, labelTime = 0;
    
    for(auto& i : a){
        fillTime += i.first;
        labelTime = max(labelTime, fillTime) + i.second;
    }
    
    return labelTime;
}

void sol(){
    ll n;
    cin >> n;
    vector<pair<ll, ll>> time(n);
    for(int i = 0; i < n; i++){
        cin >> time[i].first >> time[i].second;
    }
    
    sort(time.begin(), time.end());
    cout << maxtimecal(time) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    sol();
    return 0;
}
