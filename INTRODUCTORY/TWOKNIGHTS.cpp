#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define int long long
#define endl "\n"

int calc(int k)
{
    int total = k*k *(k*k -1)/2;
    int attack = 4 * (k-1) * (k-2);
    return total - attack;
}
signed main()
{

    int n; cin>>n;
    for(int i = 1; i <= n; i++)
    {

        cout<<calc(i)<<endl;
    }
}
