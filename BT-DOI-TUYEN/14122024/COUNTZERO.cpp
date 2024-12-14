#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
ll cnt(long long n) {
    ll count = 0;
    for (ll i = 5; n / i >= 1; i *= 5) {
        count += n / i;
    }
    return count;
}
int main() {
    ll n;
    cin >> n;
    cout << cnt(n) << endl;
    return 0;
}
