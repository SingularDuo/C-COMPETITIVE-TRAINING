#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
map<ll, ll> tang(const vector<ll>& arr) {
    map<ll, ll> dp; // Lưu độ dài dãy con tăng tại từng giá trị
    for (ll x : arr) {
        // Tìm độ dài lớn nhất từ các phần tử nhỏ hơn x
        auto it = dp.lower_bound(x); // Tìm vị trí đầu tiên >= x
        ll maxLength = 0;
        for (auto jt = dp.begin(); jt != it; ++jt) {
            maxLength = max(maxLength, jt->second);
        }
        dp[x] = maxLength + 1; // Cập nhật độ dài mới cho x
    }
    return dp;
}
int main() {
    ll n,m;
    cin>>n;
    vector<ll> a(n);
    for(ll i = 0; i<n;i++)cin>>a[i];
    cin>>m;
    vector<ll> b(m);
    for(ll i = 0;i < m; i++)cin>>b[i];
    map<ll, ll> value_a = tang(a);
    map<ll, ll> value_b = tang(b);
    ll maxx = INT_MIN;
    for(const auto& i:value_a){
        ll current = 0, bigger;
        for(const auto& j:value_b){
            if(j.first > i.first){
                maxx = max(maxx, j.first+j.first);
                cout<<i.first<<" "<<j.first<<endl;
            } 
        }
    }
    cout<<maxx;
    return 0;
}