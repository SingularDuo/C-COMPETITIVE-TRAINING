#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define endl "\n"
#define fi first 
#define se second 

signed main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<ll>> a(n, vector<ll>(m));
    vector<vector<bool>> covered(n, vector<bool>(m, false));
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++) 
        {
            cin >> a[i][j];
        }
    }

    int machine_count = 0;

    for(int i = 0; i <= n - k; i++)
    {
        for(int j = 0; j <= m - k; j++)
        {
            // Kiểm tra vùng k*k này có cần được che phủ hay không
            bool needs_coverage = false;
            for(int x = i; x < i + k; x++)
            {
                for(int y = j; y < j + k; y++)
                {
                    if(a[x][y] == 1 && !covered[x][y])
                        needs_coverage = true;
                }
            }

            if(needs_coverage)
            {
                // Đặt máy dò tại điểm (i, j) và đánh dấu vùng k*k
                machine_count++;
                for(int x = i; x < i + k; x++)
                {
                    for(int y = j; y < j + k; y++)
                    {
                        covered[x][y] = true;
                    }
                }
            }
        }
    }

    cout << machine_count << endl;
    return 0;
}
