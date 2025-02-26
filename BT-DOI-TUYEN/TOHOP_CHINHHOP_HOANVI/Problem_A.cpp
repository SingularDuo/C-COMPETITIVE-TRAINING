#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N = 1000005;
ll MOD;

ll fac[MAX_N], ifac[MAX_N];
vector<vector<ll>> C; // Mảng DP cho subtask 2

void precompute(int N) {
    C.assign(N + 1, vector<ll>(N + 1, 0));
    for (int n = 0; n <= N; ++n) {
        C[n][0] = C[n][n] = 1;
        for (int k = 1; k < n; ++k)
            C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
    }
}

long long Cnk(int n, int k) {
    if (k > n || k < 0) return 0;
    return C[n][k];
}

ll power(ll a, ll b, ll mod) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return ans;
}

void preprocess(int limit, ll mod) {
    MOD = mod;
    fac[0] = 1;
    for (int i = 1; i <= limit; ++i)
        fac[i] = (fac[i - 1] * i) % MOD;

    ifac[limit] = power(fac[limit], MOD - 2, MOD);
    for (int i = limit - 1; i >= 0; --i)
        ifac[i] = (ifac[i + 1] * (i + 1)) % MOD;
}

ll C_mod(int n, int k) {
    if (k > n) return 0;
    return fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
}

// Sử dụng DP để tính C(n, k) với subtask == 2
void computeDP(int N) {
    C.assign(N + 1, vector<ll>(N + 1, 0));
    for (int n = 0; n <= N; ++n) {
        C[n][0] = C[n][n] = 1;
        for (int k = 1; k < n; ++k)
            C[n][k] = (C[n - 1][k - 1] + C[n - 1][k]) % MOD;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int subtask, t;
    cin >> subtask >> t;
    int maxN;
    if (subtask == 1) {
        maxN = 20;
        MOD = 7102011;
        precompute(maxN);
        while (t--) {
            int n, k;
            cin >> n >> k;
            cout << Cnk(n, k) << '\n';
        }
        return 0;
    } else if (subtask == 2) {
        maxN = 1000;
        MOD = 7102011;
        computeDP(maxN);
        while (t--) {
            int n, k;
            cin >> n >> k;
            cout << C[n][k] << '\n';
        }
        return 0;
    } else if (subtask == 3) {
        maxN = 1000000;
        MOD = 1000000007;
    } else if (subtask == 4) {
        maxN = 1000000;
        MOD = 99999999999999989LL;
    } else {
        maxN = 100000;
        MOD = 7102011;
    }
    preprocess(maxN, MOD);

    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << C_mod(n, k) << '\n';
    }

    return 0;
}
