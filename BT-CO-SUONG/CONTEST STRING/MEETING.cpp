#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void sol() {
    int n;
    cin >> n;
    cin.ignore(); 
    string z;
    getline(cin, z);

    while (n--) {
        string s;
        getline(cin, s);

        map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }

        if (mp.find(z[0]) == mp.end()) {
            cout << s << endl;
        }
    }
}
signed main() {
    sol();
    return 0;
}