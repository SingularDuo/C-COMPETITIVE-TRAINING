// Problem: GGCD
// Contest: MarisaOJ - Basic Number Theory
// URL: https://marisaoj.com/problem/590
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }


    vector<int> prefix(n), suffix(n);
    prefix[0] = a[0];
    suffix[n - 1] = a[n - 1];

    for (int i = 1; i < n; i++) {
        prefix[i] = gcd(prefix[i - 1], a[i]);
    }

    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = gcd(suffix[i + 1], a[i]);
    }

    int max_gcd = 0;
    for (int i = 0; i < n; i++) {
        int new_gcd;
        
        if (i == 0) {
            new_gcd = suffix[i + 1]; 
        } 
        else if (i == n - 1) {
            new_gcd = prefix[i - 1]; 
        } 
        else {
            new_gcd = gcd(prefix[i - 1], suffix[i + 1]); 
        }

        max_gcd = max(max_gcd, new_gcd);
    }

    cout << max_gcd << endl;
}
