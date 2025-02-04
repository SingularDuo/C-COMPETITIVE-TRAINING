#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const long long MOD = 1e9 + 7;
void init(){
    freopen("BAI4.INP", "r", stdin);
    freopen("BAI4.OUT", "w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
long long val(long long idx) {
    long long left = 1, right = 100000, mid, sum;
    while (left < right) {
        mid = (left + right) / 2;
        sum = mid * (mid + 1) / 2;
        if (sum < idx)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

long long sum_in_range(long long a, long long b) {
    long long sum = 0;
    for (long long i = a; i <= b; i++) {
        sum += val(i) % MOD;
    }
    return sum % MOD;
}

void sol() {
    long long a, b;
    cin >> a >> b;
    cout << sum_in_range(a, b) << endl;
    return;
}

int main() {
    init();
    sol();
    return 0;
}