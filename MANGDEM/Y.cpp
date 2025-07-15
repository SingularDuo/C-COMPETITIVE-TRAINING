#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 8e6 + 5;
int n;
int a[N];
int cnt[N];
bool f[N];


main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];
    
    /// 3 * ap - ak = ai + aj (i < j < k)
    for(int k = 1 ; k <= n ; k++)
    {
        for(int p = 1 ; p <= n ; p++)
    		if(cnt[3 * a[p] - a[k] + (int)4e6] > 0)
    			f[p] = true;
    
    	/// i < j = k
    	for(int i = 1 ; i <= k - 1 ; i++)
    		cnt[a[i] + a[k] + (int)4e6]++;
    }
    int ans = 0;
    for(int p = 1 ; p <= n ; p++)
        if(f[p] == true)
            ans++;
    cout << ans;


}