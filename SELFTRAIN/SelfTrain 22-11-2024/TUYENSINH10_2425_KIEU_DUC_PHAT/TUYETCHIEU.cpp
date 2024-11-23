#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init() {
    freopen("TUYETCHIEU.inp", "r", stdin);
    freopen("TUYETCHIEU.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main(){
    init();
    ll n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i = 1; i <= n;i++)cin>>a[i];
    for(int i  = 1; i <= n; i++){
        int nextpos = i+k;
        for(int j=i+1; j <= nextpos; j++){
            cout<<a[i]<<" "<<a[j]<<endl;
            if(a[i] == a[j]){
                cout<<i;
                return 0;
            }
        }
    }
    cout<<"-1";
}