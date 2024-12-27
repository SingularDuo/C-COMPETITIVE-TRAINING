#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define str string
void init(){
    freopen("Congsl.inp", "r", stdin);
    freopen("Congsl.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
} 

int main() {
    init();
    str a, b;
    getline(cin, a);
    getline(cin, b);
    ll len_a = a.size();
    ll len_b = b.size();
    ll len = max(len_a, len_b);
    vector<int> res(len + 1, 0);
    ll carry = 0;
    while (a.size() < len) a = "0" + a;
    while (b.size() < len) b = "0" + b;
    for (ll i = len - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        res[i + 1] = sum % 10;
        carry = sum / 10;
    }
    res[0] = carry; 
    bool leading_zero = true;
    for (int i = 0; i <= len; i++) {
        if (res[i] == 0 && leading_zero) continue;
        leading_zero = false;
        cout << res[i];
    }
    if (leading_zero) cout << 0;
    cout << endl;

    return 0;
}
