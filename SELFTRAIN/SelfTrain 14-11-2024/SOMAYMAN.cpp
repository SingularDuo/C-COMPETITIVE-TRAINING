#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int MOD = 100000;

int main() {
    vector<ll> a(MOD, 0);
    for (int i = 0; i < MOD; i++) {
        if (i % 3 == 2) {
            a[i] = 1;
        }
    }
    ll n;
    cin >> n;
    vector<ll> luu(n);
    for (int i = 0; i < n; i++) luu[i] = i + 1; 
    ll i = 0;
    while (luu.size() > 1) {
        i = i % luu.size(); 
         if (a[luu[i] % MOD] != 1) { 
            luu.erase(luu.begin() + i);
        } else {
            i++;
        }
    }

    cout << luu.front() << endl; 
    return 0;
}
