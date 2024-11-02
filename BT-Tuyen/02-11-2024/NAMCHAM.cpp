#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main() {
    int n;
    cin >> n;
    cin.ignore();
    string s;
    vector<string> magnets(n);

    for (int i = 0; i < n; i++) {
        getline(cin, magnets[i]);
    }
    ll cnt = 1; 
    for (int i = 1; i < n; i++) {
        if (magnets[i] != magnets[i - 1]) {
            cnt++;
        }
        else continue;
    }
    cout << cnt << endl;
    return 0;
}