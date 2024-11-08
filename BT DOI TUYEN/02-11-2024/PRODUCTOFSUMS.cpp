#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<int>a(n);
        ll cnt = 0;
        for(ll i =0; i < n; i++)
        {
            cin>>a[i];
            cnt++;
        }
        int bentrai = n/2;
        ll tongtrai = 0;
        ll tongphai  = 0;
        for(ll i = 0; i < bentrai; i++)tongtrai += a[i];
        for(ll i = bentrai; i < n;i++)tongphai += a[i];
        cout<<tongtrai * tongphai<<endl;
    }
}