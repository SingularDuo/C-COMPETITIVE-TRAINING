#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back

const int maxn = 1e6; 
bool isprime[maxn + 1];

void sieve() {
    fill(isprime, isprime + maxn + 1, true);
    isprime[0] = isprime[1] = false;
    for (int i = 2; i * i <= maxn; i++) {
        if (isprime[i]) {
            for (int j = i * i; j <= maxn; j += i) {
                isprime[j] = false;
            }
        }
    }
}

signed main() {
    faster;
    sieve();
    
    int n;
    cin >> n;
    vector<int> a(n), mark;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (isprime[i + 1]) mark.pb(i); 
    }
    if (mark.empty()) {
        cout << "0\n";
        return 0;
    }

    vector<int> f(n);
    f[0] = a[0];
    for (int i = 1; i < n; i++) {
        f[i] = f[i - 1] + a[i];
    }

    int maxx = LLONG_MIN;
    for (size_t i = 0; i < mark.size(); i++) {
        for (size_t j = i; j < mark.size(); j++) { 
            int sum;
            if (mark[i] == 0) sum = f[mark[j]];
            else sum = f[mark[j]] - f[mark[i] - 1];
            
            maxx = max(maxx, sum);
        }
    }

    cout << maxx << "\n";
}
