#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define int long long
#define endl "\n"

signed main()
{
    int n; cin>>n;
    map<int, int> freq;
    for(int i = 0; i < n; i++)
    {
        int a; cin>>a;
        freq[a]++;
    }
    cout<<freq.size();
}