#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void sol(){
    ll n;
    cin >> n;
    n *= 2;
    
    int res = 0;    
    for (long long i=2; i*i<=n; ++i)
    if (n % i == 0)
    {
        if (n/i == i) continue;

        long long a = i;
        long long b = n/i;

        res += ((b - a + 1) % 2 == 0 && (b + a - 1) % 2 == 0);
    }
    cout<<res;
    return;
}
signed main() {
    sol();
    return 0;
}