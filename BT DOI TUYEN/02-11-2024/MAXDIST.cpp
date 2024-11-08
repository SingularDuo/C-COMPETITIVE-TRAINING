#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n;i++)cin>>a[i];
        vector<int> danhdau(1e4+5, 0);
        vector<int> start(1e4+5, -1);
        vector<int> end(1e4+5, -1);
        for(int i = 0; i < n;i++){
            danhdau[a[i]]++;
            end[a[i]] = i;
            if(danhdau[a[i]] == 1) start[a[i]] = i;
        }
        vector<pair<int, int>>cap;
        for(int i = 0; i < start.size();i++) 
        {
            if(start[i] != -1 && end[i] != -1){
                cap.push_back({start[i], end[i]});
            }
        }
        int maxx = 0;
        for(int i = 0; i < cap.size(); i++){
            int curr =  cap[i].second - cap[i].first;
            maxx = max(maxx, curr);
        }
        cout<<maxx<<endl;;
    }
}