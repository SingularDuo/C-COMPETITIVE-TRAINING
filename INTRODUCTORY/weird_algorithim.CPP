#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
signed main()
{
    int n;
    cin>>n;
    cout<<n<<" ";
    while(n != 1)
    {
        if(n % 2 == 0)
        {
            n /= 2;
            cout<<n<<" ";
        }
        else if(n % 2 != 0)
        {
            n = n*3 + 1;
            cout<<n<<" ";
        }
        else if(n ==1)
        {
            cout<<1;
            return 0;
        }
    }
    return 0;
}
