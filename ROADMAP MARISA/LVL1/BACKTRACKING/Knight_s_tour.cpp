#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};  
int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};  

int n, m;
int need = 1;
vector<vector<ll>> a;  
vector<vector<bool>> visited; 

bool ValidCell(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < m && !visited[r][c]); 
}
bool ok = false;
void knights(ll curr_x, ll curr_y, ll times) {
    a[curr_x][curr_y] = times;
    visited[curr_x][curr_y] = true;
    if(ok)return;

    if (times == need) { 
        ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        exit(0); 
    }

    for (int i = 0; i < 8; i++) {
        int nx = curr_x + dx[i];
        int ny = curr_y + dy[i];

        if (ValidCell(nx, ny)) {
            knights(nx, ny, times + 1);
        }
    }
    a[curr_x][curr_y] = 0;
    visited[curr_x][curr_y] = false;
}

KING_PHAT {
    fast;
    cin >> n >> m;
    need = n * m;

    a.assign(n, vector<ll>(m, 0));
    visited.assign(n, vector<bool>(m, false));

    knights(0, 0, 1); 

    cout << "-1\n";
}
/*
#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
typedef long long ll;
using namespace std;

bool ok=false;
int n,m;
int a[8][8];
int dx[]={-2,-2,-1,-1,1,1,2,2};
int dy[]={-1,1,-2,2,-2,2,-1,1};

void waylouis(int x,int y,int c)
{
    if(ok) return;
    a[x][y]=c;
    if(c==n*m)
    {
        ok=true;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++) cout << a[i][j] << ' ';
            cout << endl;
        }
        return;
    }
    for(int i=0;i<8;i++)
    {
        int xx=x+dx[i],yy=y+dy[i];
        if(xx<1||yy<1||xx>n||yy>m) continue;
        if(!a[xx][yy]) waylouis(xx,yy,c+1);
    }
    a[x][y]=0;
}

void solve()
{
    cin >> n >> m;
    waylouis(1,1,1);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}
*/