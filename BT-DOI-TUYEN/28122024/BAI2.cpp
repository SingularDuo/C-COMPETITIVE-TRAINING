#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, a;
    cin >> n >> a;
    ll total = n * (2 + (n - 1) * a) / 2;
    cout << total << endl;
    return 0;
}
