#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

string limit = "1000000000000000000";

string chia2(string num) {
    string result;
    int carry = 0;
    bool leadingZero = true;

    for (char c : num) {
        int cur = carry * 10 + (c - '0');
        int quotient = cur / 2;
        carry = cur % 2;

        if (quotient == 0 && leadingZero) continue;
        leadingZero = false;
        result += (quotient + '0');
    }

    return result.empty() ? "0" : result;
}

ll calculateab2(ll amod, string b, ll Mod) {
    if (b == "0") return 1;
    if (b == "1") return amod % Mod;

    bool odd = (b.back() - '0') % 2; 
    ll half = calculateab2(amod, chia2(b), Mod);
    ll result = (half * half) % Mod;

    if (odd) result = (result * amod) % Mod;
    return result;
}

void sol() {
    string a, b;
    ll MOD;
    cin >> a >> b >> MOD;

    ll amod = 0;
    for (char c : a) {
        amod = (amod * 10 + (c - '0')) % MOD;
    }
    cout << calculateab2(amod, b, MOD) << endl;
}

signed main() {
    sol();
    return 0;
}
