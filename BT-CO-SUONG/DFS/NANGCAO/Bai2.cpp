#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KInG_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
void init()
{
    freopen("BAI2.INP", "r", stdin);
    freopen("BAI2.OUT", "w", stdout);
    fast;
}
const int maxn = 1001;
int n,m;     
int ans; 
int farm[maxn][maxn];  
bool Visit[maxn][maxn]; 
bool peak;          
int dr[8] = {-1,-1,-1, 0,0, 1,1,1};
int dc[8] = {-1, 0, 1,-1,1,-1,0,1};
void DFS(int row, int col)
{
	Visit[row][col] = true;
	for(int i = 0; i < 8; i++)
	{
		int r = row + dr[i];
		int c = col + dc[i];

		if(r >= 0 && r < n && c >= 0 && c < m)
		{
			if(peak && farm[r][c] > farm[row][col]) peak = false;
			if(farm[r][c] == farm[row][col] && !Visit[r][c]) DFS(r, c);
		}
	}
}

KInG_PHAT
{
    init();
	cin>>n>>m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			cin >> farm[i][j];
			Visit[i][j] = false;
		}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(!Visit[i][j])
			{
				peak = true;
				DFS(i, j);
				if(peak) ans++;
			}

	cout << ans << endl;

	return 0;
}