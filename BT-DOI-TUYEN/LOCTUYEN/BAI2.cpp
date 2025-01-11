#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int maxn = 1e6; // se sua theo gioi han de bai
int main(){
    ll n;
    cin>>n;
    int a[n+1];
    int danhdau[maxn];
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        danhdau[a[i]] = 1;
    }
    ll cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            ll maxx = max(abs(a[i]), abs(a[j]));
            ll minn = min(abs(a[i]), abs(a[j]));
            ll target = (abs(a[i]) + abs(a[j]))/2;
            if(maxx - target == target - minn && danhdau[target] == 1){
                cnt++;
            }
        }
    }
    cout<<cnt;

}


