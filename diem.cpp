#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

string limit = "1000000000000000000";

ll calculateAmod(string a, ll Mod) {
    ll res = 0;
    for (char c : a) {
        res = (res * 10 + (c - '0')) % Mod;
    }
    return res;
}

string chia2(string num) {
    string bin = "";
    ll dec = 0;

    for (char c : num) {
        dec = dec * 10 + (c - '0');
    }

    while (dec > 0) {
        bin += (dec % 2) + '0'; 
        dec /= 2; 
    }

    reverse(bin.begin(), bin.end());

    if (!bin.empty()) {
        bin.pop_back();
    }

    return bin.empty() ? "0" : bin;
}

ll calculateab2(string a, string b, ll Mod) {
    ll A = calculateAmod(a, Mod);

    if (b == "0") return 1;
    if (b == "1") return A % Mod;

    bool odd = (b.back() - '0') % 2; 
    ll half = calculateab2(a, chia2(b), Mod);
    ll result = (half * half) % Mod;

    if (odd) result = (result * A) % Mod;
    return result;
}

void sol() {
    string a, b;
    cin >> a >> b;
    ll MOD;
    cin >> MOD;

    cout << calculateab2(a, b, MOD) << endl;
}

signed main() {
    sol();
    return 0;
}
