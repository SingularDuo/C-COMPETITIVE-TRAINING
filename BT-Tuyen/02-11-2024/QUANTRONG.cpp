#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int main(){
    ll n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0; i < n;i++)cin>>a[i];
    ll max_val = *max_element(a.begin(), a.end());
    vector<pair<int, int>> pos;
    vector<int> danhdau(max_val+5, 0);
    vector<int> start(max_val+5, -1);
    vector<int> end(max_val+5, -1);
    for(int i = 0; i < n;i++){
        danhdau[a[i]]++;
        end[a[i]] = i;
        if(danhdau[a[i]] == 1) start[a[i]] = i;
    }
    for(int i = 0; i <= max_val; i++){
        if(start[i] != -1 && end[i] != -1){
            pos.push_back({start[i], end[i]});
        }
    }
    ll maxx = 0;
    for(int i = 0; i < pos.size(); i++){
        ll curr = 0;
        //cout<<pos[i].first<<" "<<pos[i].second<<endl;
        for(int j = pos[i].first; j <= pos[i].second; j++){
            curr += a[j];
        }
        if(curr > maxx) maxx = curr;
    }
    cout<<maxx<<endl;
}