#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n , x, res;
ll prefix[100005];
map<int, int> mp;
int main()
{
    cin>>n>>x;
    for(int i = 1; i <= n; i++)
    {
        ll temp; cin>>temp;
        prefix[i] = prefix[i-1] + temp;
        mp[prefix[i]]++;
        res += mp[prefix[i] - x];
        if(prefix[i] == x && prefix[i] - x != prefix[i])res++;
    }
    cout<<res;
    return 0;
}
