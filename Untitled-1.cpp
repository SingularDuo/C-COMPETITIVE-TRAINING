#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int n, k;
map<int, int> cnt;
int main(){
    cin>>n>>k;
    int a[n+1];
    for(int i = 1; i <= n; i++){
        int b;      
        cin>>b;
        a[i] = b;
        cnt[b]++;
    }
    int res = 0;

    for(int i = 1; i <=  n;i++){
        int target = k - a[i];
        if(cnt[target].second != 0) res++;
        else continue;
    }
}