#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

bool palin(string s) {
    string s1 = s;
    reverse(s1.begin(), s1.end());
    return s1 == s;
}

void sol() {
    int t;
    cin >> t;   
    cin.ignore(); 

    while (t--) {
        string s;
        getline(cin, s);
        ll k;
        cin >> k;
        cin.ignore(); 

        if (palin(s)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return;
}

signed main() {
    sol();
    return 0;
}