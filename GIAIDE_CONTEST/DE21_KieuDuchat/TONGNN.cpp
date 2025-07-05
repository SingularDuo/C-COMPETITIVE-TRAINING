#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define endl "\n"

int lcm(int a, int b) {
    return (a / __gcd(a, b)) * b;
}
/*
Gọi A = m * x, B = m * y thì ta có:

=))) author: KduckP
    UCLN(A, B) = m, do m là ước chung.

    Khi đó: LCM(A, B) = LCM(m * x, m * y) = m * LCM(x, y)
*/
const int SUB1 = 7*1e3;
signed main() {
    freopen("TONGNN.INP", "r", stdin);
    freopen("TONGNN.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m, n;
    cin >> m >> n;
    if(n - m <= SUB1)
    {
        int res = LLONG_MAX;
        for(int i = m; i <= n; i++)
        {
            for(int j = i + 1; j <= n; j++)
            {
                if(__gcd(i, j) == m && lcm(i, j) == n)
                {
                    res = min(res, i + j);
                }
            }
        }
        if(res == LLONG_MAX)
        {
            cout<<-1;
            return 0;
        }
        cout<<res;
        return 0;
    }
    if (n % m != 0) {
        cout << -1 << endl;
        return 0;
    }

    int k = n / m;
    int ans = LLONG_MAX;
    for (int x = 1; x * x <= k; ++x) {
        if (k % x == 0) {
            int y = k / x;

            if (lcm(x, y) == k) {
                int sum = m * (x + y);
                ans = min(ans, sum);
            }
        }
    }

    if (ans == LLONG_MAX) cout << -1 << endl;
    else cout << ans ;

    return 0;
}
