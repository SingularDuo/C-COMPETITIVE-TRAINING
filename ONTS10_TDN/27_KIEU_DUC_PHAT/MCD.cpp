#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"
void init()
{
    freopen("MCD.INP", "r", stdin);
    freopen("MCD.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int tinhchuso(int x)
{
    int res = 0;
    while (x > 0)
    {
        res += x % 10;
        x /= 10;
    }
    return res;
}

int main()
{
    init();
    int a, b;
    cin >> a >> b;
    int minn = min(a, b);
    int maxx = max(a, b);
    int res = LLONG_MIN;

    for (int i = 1; i * i <= minn; i++)
    {
        if (minn % i == 0)
        {
            if (maxx % i == 0)
            {
                res = max(res, tinhchuso(i));
            }
            int other = minn / i;
            if (maxx % other == 0)
            {
                res = max(res, tinhchuso(other));
            }
        }
    }

    cout << res << endl;
    return 0;
}
