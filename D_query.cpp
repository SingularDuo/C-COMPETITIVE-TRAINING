#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

KING_PHAT
{
    fast;
    int n;
    cin >> n;
    vector<ll> a(n);
    map<int, int> counting;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        counting[a[i]]++;
    }

    int q; 
    cin >> q;
    vector<pair<ll, ll>> d(q);
    for(int i = 0; i < q; i++) cin >> d[i].first >> d[i].second;
    vector<ll> precompute(n);
    precompute[0] = 1;
    counting[a[0]]--;
    for(int i = 1; i < n; i++)
    {
        
    }
    if(n <= pow(10, 4) && q <= pow(10, 5))
    {
        for(int i = 0; i < q; i++)
        {
            int start = d[i].first - 1, end = d[i].second - 1;
            set<int> current;
            for(int j = start; j <= end; j++)
            {
                current.insert(a[j]);
            }
            cout << current.size() << endl;
        }
    }
    
    return 0;
}
