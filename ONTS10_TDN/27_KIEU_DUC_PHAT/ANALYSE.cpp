#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl "\n"
void init()
{
    freopen("ANALYSE.INP", "r", stdin);
    freopen("ANALYSE.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
map<int, int> cnt;
void pttsnt(int n) {
    vector<int> x;

    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            x.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        x.push_back(n);
    }
    for(auto i : x)
    {
        cnt[i]++;
    }
}
signed main()
{
    init();
    int n;
    cin>>n;
    for(int i = 2; i <= n; i++)
    {
        pttsnt(i);
    }
    for(auto& i : cnt)
    {
        if(i.second > 0)
        {
            cout<<i.second<<" ";
        }
    }
    return 0;

}
