#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define int long long

map<int, int> res;

void duyet_uoc(int x)
{
    int sqrtX = sqrt(x);
    for (int i = 1; i <= sqrtX; i++)
    {
        if (x % i == 0)
        {
            res[i]++;
            if (i != x / i) res[x / i]++;
        }
    }
}

signed main()
{
    freopen("CDIV.inp", "r", stdin);
    freopen("CDIV.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        duyet_uoc(a);
    }

    for (auto it = res.rbegin(); it != res.rend(); it++) 
    {
        if (it->second >= 2)
        {
            cout << it->first << endl;
            break;
        }
    }

    return 0;
}
