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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> sub = a;
    sort(a.begin(), a.end());
    
    for (int i = 0; i < n - 2; i++)
    {
        int it1 = i + 1;
        int it2 = n - 1;

        while (it1 < it2)
        {
            ll current_sum = a[i] + a[it1] + a[it2];
            if (current_sum == k)
            {
                vector<ll> current;
                map<int, int> l;
                for(int j = 0; j < n; j++)
                {
                    if(sub[j] == a[i])
                    {
                        l[j]++;
                        current.push_back(j+1);
                        break;
                    }
                }
                for(int j = 0; j < n; j++)
                {
                    if(sub[j] == a[it1]&&l[j]==0)
                    {
                        l[j]++;
                        current.push_back(j+1);
                        break;
                    }
                }
                for(int j = 0; j < n; j++)
                {
                    if(sub[j] == a[it2]&&l[j]==0)
                    {
                        current.push_back(j+1);
                        break;
                    }
                }
                sort(current.begin(), current.end());
                for(auto& i : current)cout<<i<<" ";
                return 0;
            }
            else if (current_sum < k)
            {
                it1++; 
            }
            else
            {
                it2--;
            }
        }
    }
    return 0;
}