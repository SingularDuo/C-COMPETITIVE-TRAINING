#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define int long long
#define endl "\n"

signed main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);

    int l, r; cin>>l>> r;

    for(int i = l; i <= r; i++)
    {
        for(int j = r; j >= l; j--)
        {
            if(__gcd(i, j) == 1 && i != j)
            {
                cout<< j - i;
                return 0;
            }
        }
    }
    cout<<-1;
}
