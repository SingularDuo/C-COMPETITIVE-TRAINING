#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main()
{
    int n, q;
    cin>>n>>q;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)cin>>a[i];
    sort(a.begin(), a.end());
    vector<ll> query(q);
    for(int i = 0; i < q; i++)cin>>query[i];

    for(auto i : query)
    {
        ll currans = -1;
        ll l = 0, r = a.size()-1;
        while(l <= r)
        {
            int mid = (l + r)/2;
            if(a[mid] <= i)
            {
                l = mid + 1;
                currans = mid;
            }
            else r = mid-1;
        }
        if(currans == -1)
        {
            cout<<-1<<endl;
            continue;
        }
        else cout<<currans+1<<endl;
    }
}
