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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<int> ans;
    bool xuong = true;
    for(int i = 0; i < m; i++)
    {
        ll subi = i;
        ll j = 0;
        vector<ll> current;
        while(j < n && subi >= 0)
        {
            current.push_back(a[j][subi]);
            j++;
            subi--;
        }
        if((i+1) % 2 == 0)
        {
            for(int j = 0; j < current.size(); j++)
            {
                ans.push_back(current[j]);
            }
            xuong = true;
        }
        else 
        {
            for(int j = current.size() - 1; j >= 0; j--)
            {
                ans.push_back(current[j]);
            }
            xuong = false;
        }
    }
    for(int i = 1; i < n; i++)
    {
        ll subi = m - 1;
        ll j = i;
        vector<ll> current;
        while(j < n && subi >= 0)
        {
            current.push_back(a[j][subi]);
            j++;
            subi--;
        }
        if(!xuong)
        {
            xuong = true;
            for(int j = 0; j < current.size(); j++)
            {
                ans.push_back(current[j]);
            }
        }
        else 
        {
            xuong = false;
            for(int j = current.size() - 1; j >= 0; j--)
            {
                ans.push_back(current[j]);
            }
        }
    }
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}