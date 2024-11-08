#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init() {
    freopen("2_16.inp", "r", stdin);
    freopen("2_16.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main(){
    init();
    string s;
    getline(cin, s);
    int a = s.size() - 1;
    ll final = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            final += pow(2, a);
        }
        a--;
    }
    vector<ll> vec;
    while(final > 0){
        ll a = final % 16;
        vec.push_back(a);
        final /= 16;
    }
    for (ll i = vec.size() - 1; i >= 0; i--) {
        if (vec[i] < 10) {
            cout << vec[i];
        } else {
            cout << char('A' + vec[i] - 10);
        }
    }
}