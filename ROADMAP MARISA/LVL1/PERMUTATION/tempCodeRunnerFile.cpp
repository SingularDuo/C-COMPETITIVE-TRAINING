#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void genper(ll s, string a)
{
    if(a.size()==s){
        vector<ll> cnt(10,0);
        for (int i = 0; i < a.size(); i++) {
            cnt[a[i]-'0']++;
        }
        for(auto i : cnt){
            if(i > 1)return;
        }
        for(auto i : a){
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    for (ll i = 1; i <= s; i++) {
        string new_a = a + to_string(i);
        genper(s, new_a);
    }
}
void sol(){
    ll s;
    cin>>s;
    genper(s, "");
    return;
}
signed main() {
    sol();
    return 0;
}