#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init() {
    freopen("16_2.inp", "r", stdin);
    freopen("16_2.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main(){
    init();
    string s;
    getline(cin, s);
    ll final = 0;
    ll a = s.size() - 1;
    for (ll i = 0; i < s.size(); i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            final += (s[i] - '0') * pow(16, a);
        } 
        else if ('A' <= s[i] && s[i] <= 'F') {
            final += (s[i] - 'A'+10) * pow(16, a);
        }
        a--;
    }
    vector<ll> vec;
    while (final > 0) {
        ll a = final % 2;
        vec.push_back(a);
        final /= 2;
    }
    for (ll i = vec.size() - 1; i >= 0; i--) {
        cout << vec[i];
    }
    cout << endl;

}