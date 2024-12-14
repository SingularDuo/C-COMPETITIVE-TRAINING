#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define pb push_back
#define endl "\n"

long long maxx(int n) { 
    if (n == 2) return 1; 
    if (n == 3) return 2; 
    ll product = 1; 
    while (n > 4) { 
        product *= 3; 
        n -= 3; 
    } 
    product *= n; 
    return product; 
} 

int main() { 
    ll n; 
    cin >> n; 
    ll res = maxx(n); 
    cout << res << endl; 
    return 0;
}
