#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define vec(type, a, size, value) vector<type> a(size, value);
#define all(x) x.begin(), x.end()
#define I_O(input_name, output_name) freopen((string(input_name) + ".inp").c_str(), "r", stdin); freopen((string(output_name) + ".out").c_str(), "w", stdout); fast;

bool normalcheck(int x) {
    if (x <= 1) return false;
    if (x == 2 || x == 3 || x == 5) return true;
    if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0) return false;

    for (int i = 5; i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

vector<bool> sieve_in_range(int l, int r) {
    const int maxx = r - l + 1;
    vector<bool> isprime_in_range(maxx, true);
    for(int i = 0; i <= maxx; i++)isprime_in_range[i] = true;
    for (int i = 2; i * i <= r; i++) {
        for (ll j = max(i*i,((l + i - 1) / i * i)); j <= r; j += i) {
            isprime_in_range[j - l] = false;
        }
    }

    if (l == 1) isprime_in_range[0] = false;
    return isprime_in_range;
}

void sol() {
    int l, r;
    cin >> l >> r;

    vector<bool> isprime_in_range = sieve_in_range(l, r);

    /*for (int i = 0; i < isprime_in_range.size(); i++) {
        cout << (l + i) << " is prime? " << (isprime_in_range[i] ? "Yes" : "No") << endl;
    }*/

    //cout << "Primes in range: ";
    //cout<<l<<" "<<r<<endl;
    for (int i = l; i <= r; i++) {
        if (isprime_in_range[i - l]) cout << i << " ";
    }
    cout << endl;
}

signed main() {
    //I_O("Segmented", "Segmented");
    fast;
    sol();
    return 0;
}
