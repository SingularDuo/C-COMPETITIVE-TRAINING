#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
bool sumset(const vector<ll>&a, ll start_pos, ll k){
    if(k == 0)return true;
    if(k < 0 || start_pos == a.size())return false;
    if(sumset(a, start_pos + 1, k - a[start_pos]))return true;
    if(sumset(a, start_pos + 1, k))return true;
    return false;
}
void sol(){
    ll n, k;
    cin>>n>>k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)cin>>a[i];
    if(sumset(a, 0, k)){
        cout<<"YES";
        return;
    }
    else cout<<"NO";
    return;
}
signed main() {
    sol();
    return 0;
}