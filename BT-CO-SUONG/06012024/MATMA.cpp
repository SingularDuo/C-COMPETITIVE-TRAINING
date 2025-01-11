#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init() {
    freopen("MATMA.INP", "r", stdin);
    freopen("MATMA.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);     
    cin.tie(0);
    cout.tie(0);
}
int main() {
    init();
    string s;
    getline(cin, s); 
    vector<ll> luu; 

    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) { 
            ll current = 0;
            while (i < s.size() && isdigit(s[i])) { 
                current = current * 10 + (s[i] - '0');
                i++;
            }
            luu.push_back(current); 
        }
    }
    sort(luu.begin(), luu.end(), greater<ll>());
    ll res = luu[0] - luu[luu.size() - 1];
    cout << res << endl; 
    return 0;
}
// 12asd4efg5ett69