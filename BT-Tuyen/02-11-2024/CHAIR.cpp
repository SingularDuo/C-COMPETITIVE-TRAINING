#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int main(){
    ll n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0; i < n;i++)cin>>a[i];
    vector<pair<int, int>> pos;
    vector<int> danhdau(1e3+5, 0);
    for(int i = 0; i < n; i++){
        danhdau[a[i]]++;
        int start = i;
        if(danhdau[a[i]] != 1) continue;
        int end = INT_MIN;
        for(int j = i; j < n; j++){
            if(a[j] == a[i]){
                if(j > end){
                    end = j;
                }
            }
        }
        pos.push_back({start, end});
    }
    ll maxx = 0;
    for(int i = 0; i < pos.size(); i++){
        int curr = 0;
        //cout<<pos[i].first<<" "<<pos[i].second<<endl;
        for(int j = pos[i].first; j <= pos[i].second; j++){
            curr += a[j];
        }
        if(curr > maxx) maxx = curr;
    }
    cout<<maxx;
}