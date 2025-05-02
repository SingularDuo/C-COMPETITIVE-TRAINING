#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define vec(type, a, size, value) vector<type> a(size, value);
#define all(x) x.begin(), x.end()
#define I_O(input_name, output_name) freopen((string(input_name) + ".inp").c_str(), "r", stdin); freopen((string(output_name) + ".out").c_str(), "w", stdout); fast;

bool multitest = false;

void init() {
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    fast;
}

void solve() {
    const int MAX_LIMIT = 6000000;
    const int PRIME_LIMIT = 400000;
    
    vector<bool> is_prime(MAX_LIMIT + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAX_LIMIT; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX_LIMIT; j += i) {
                is_prime[j] = false;
            }
        }
    }
    
    vector<int> primes;
    primes.reserve(PRIME_LIMIT);
    for (int i = 2; i <= MAX_LIMIT && primes.size() < PRIME_LIMIT; i++) {
        if (is_prime[i]) primes.push_back(i);
    }
    
    int num_primes = primes.size();
    vector<ll> prime_sum(num_primes + 1, 0);
    for (int i = 1; i <= num_primes; i++) {
        prime_sum[i] = prime_sum[i - 1] + primes[i - 1];
    }
    
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        int n;
        cin >> n;

        vector<ll> elements(n);
        for (int i = 0; i < n; i++) cin >> elements[i];
        sort(all(elements), greater<ll>());
        
        vector<ll> cumulative_sum(n + 1, 0);
        for (int i = 1; i <= n; i++) cumulative_sum[i] = cumulative_sum[i - 1] + elements[i - 1];
        
        int threshold = 0;
        for (int i = 1; i <= n && i <= num_primes; i++) {
            if (cumulative_sum[i] >= prime_sum[i]) threshold = i;
            else break;
        }
        cout << (n - threshold) << endl;
    }
}

KING_PHAT {
    // Set multitest state
    // multitest = true;
    // Set I/O style
    // I_O("test1", "test1");
    fast;
    if (multitest) {
        int t;
        cin >> t;
        while (t--) {
            solve();
        }
    } else {
        solve();
    }
    return 0;
}
