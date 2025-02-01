#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

string day(string x) {
    string res = x.substr(1) + x[0];
    return res;
}

int main() {
    string s;
    getline(cin, s); 
    string ans = "";
    for (int i = 0; i < s.size(); ++i) { 
        ans += s[i];
        ans = day(ans); 
    }
    cout << ans << endl; 
    return 0;
}
// dxmhloventha