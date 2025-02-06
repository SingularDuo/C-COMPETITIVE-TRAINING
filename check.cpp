#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
string nhan(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    vector<int> result(n + m, 0);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int mul = (s1[i] - '0') * (s2[j] - '0');
            int sum = mul + result[i + j + 1]; 
            result[i + j + 1] = sum % 10;   
            result[i + j] += sum / 10;      
        }
    }
    string res = "";
    bool leadingZero = true;
    for (int num : result) {
        if (num == 0 && leadingZero) continue; 
        leadingZero = false;
        res += to_string(num);
    }
    if(res.empty())return 0;
    else return res;
}
void sol(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i = 0; i < n;i++)cin>>a[i];
    string res = "1";
    for(ll i = 0; i < n; i++){
        res = nhan(res, to_string(a[i]));
    }
    cout<<res;
    return;
}
signed main() {
    sol();
    return 0;
}