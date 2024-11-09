#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main(){
    ll n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int max_val = *max_element(a.begin(), a.end());
    vector<int> danhdau(max_val + 1, 0);
    vector<int> start(max_val + 1, -1);
    vector<int> end(max_val + 1, -1);
    
    for(int i = 0; i < n; i++) {
        danhdau[a[i]]++;
        end[a[i]] = i;
        if(danhdau[a[i]] == 1) start[a[i]] = i;
    }
    vector<pair<int, int>> pos;
    for(int i = 0; i < n; i++) {
        if(start[a[i]] != -1 && end[a[i]] != -1) {
            pos.push_back({start[a[i]], end[a[i]]});
            start[a[i]] = -1; 
        }
    }
    
    ll maxx = 0;
    for(int i = 0; i < pos.size(); i++) {
        ll curr = 0;
        //cout<<pos[i].first<<" "<<pos[i].second<<endl;
        for(int j = pos[i].first; j <= pos[i].second; j++) {
            curr += a[j];
        }
        if(curr > maxx) maxx = curr;
    }
    cout<<maxx<<endl;
}