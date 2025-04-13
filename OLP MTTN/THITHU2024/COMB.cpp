#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

int sumdiv(int a, int b) {
    int g = __gcd(a, b); 
    int sum = 0;
    for (int i = 1; i * i <= g; i++) {
        if (g % i == 0) {
            sum = (sum + i) % MOD; 
            if (i != g / i) {
                sum = (sum + g / i) % MOD; 
            }
        }
    }
    return sum;
}

signed main() {
    fast;
    int n;
    cin >> n;
    int res = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {  
            res = (res + sumdiv(i, j)) % MOD;
        }
    }
    cout << res << endl;
}
