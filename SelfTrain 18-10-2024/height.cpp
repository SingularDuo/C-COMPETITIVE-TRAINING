#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6;
int cnt[maxn + 5];
const int MOD = 1e9 + 7;
void sol() {
    int n;
    cin>>n;
    vector<int> truoc;
    vector<int> sau;
    for(int i = 0 ; i< n; i++){
        int a;
        cin>>a;
        truoc.push_back(a);
    }
    for(int i = 0; i< n; i++){
        int a;
        cin>>a;
        sau.push_back(a);
    }
    vector<int>chenhlech(n);
    int maxx = INT_MIN;
    for(int i = 0; i < n; i++){
        int diff = sau[i] - truoc[i];
        if(diff > maxx) maxx = diff;
        chenhlech[i] = diff;
    }
    for(int i = 0; i< n; i++){
        if(chenhlech[i] == maxx) cout<<i+1<<" ";
    }
}

int main() {
    sol();
    return 0;
}
