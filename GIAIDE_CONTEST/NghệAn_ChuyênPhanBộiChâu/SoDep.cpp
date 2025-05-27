#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;
const int MAX_N = 1e6+20;

vector<int> highest_pow_5(MAX_N, 0);
vector<int> f(MAX_N, 0);

void precompute() {
    for (int i = 5; i < MAX_N; i *= 5) {
        for (int j = i; j < MAX_N; j += i) {
            highest_pow_5[j]++;
        }
    }
    
    for (int i = 1; i < MAX_N; i++) {
        f[i] = (f[i-1] + highest_pow_5[i]) % MOD;
    }
}
vector<int> highest_pow_2(MAX_N, 0);
vector<int> fs(MAX_N, 0);

void precompute2() {
    for (int i = 2; i < MAX_N; i *= 2) {
        for (int j = i; j < MAX_N; j += i) {
            highest_pow_2[j]++;
        }
    }
    
    for (int i = 1; i < MAX_N; i++) {
        fs[i] = (fs[i-1] + highest_pow_2[i]) % MOD;
    }
}

void solve() {
    int a, b;
    cin >> a >> b;
    int result = min(((f[b] - f[a-1] + MOD) % MOD), ((fs[b] - fs[a-1] + MOD) % MOD));  
    cout << result << endl;
}       

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    precompute2();
    precompute();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
