#include<bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    
    string res = "";
    for (size_t i = 0; i < s.length(); ) {
        if (s[i] == '.') {
            res += '0';
            i++;
        } else if (i + 1 < s.length() && s[i] == '-' && s[i + 1] == '.') {
            res += '1';
            i += 2;
        } else if (i + 1 < s.length() && s[i] == '-' && s[i + 1] == '-') {
            res += '2';
            i += 2;
        }
    }
    
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    return 0;
}
