#include <bits/stdc++.h>
using namespace std;
#define ll long long

void turnback(ll n, vector<bool>& a)
{
    if (n <= 2) {
        a[n] = true;
        return;
    }

    if (n % 2 != 0)
    {
        if (n % 10 != 1) return;
        a[n] = true;
        while (n % 10 == 1) {
            n /= 10;
            a[n] = true;
        }
        turnback(n, a);
    }
    else if (n % 10 == 6) return;
    else
    {
        a[n] = true;
        while (n % 2 == 0) {
            n /= 2;
            a[n] = true;
        }
        turnback(n, a);
    }
}

int main()
{
    ll q;
    cin >> q;
    while (q--)
    {
        ll a, b;
        cin >> a >> b;

        vector<bool> cnt(b + 1, false);
        turnback(b, cnt);

        if (a <= b && cnt[a]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
