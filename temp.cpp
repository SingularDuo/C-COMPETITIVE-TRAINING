#include <bits/stdc++.h>
using namespace std;
#define ll long long
int dx[2] = {1, 0};
int dy[2] = {0, 1};
vector<vector<ll>> a(6, vector<ll>(6, 0));
ll res = LLONG_MIN;

void gen(ll point, int x, int y)
{
    if (x == 4 && y == 4)
    {
        res = max(res, point);
        return;
    }
    for (int i = 0; i < 2; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && nx <= 4 && ny >= 1 && ny <= 4)
        {
            gen(point + a[nx][ny], nx, ny);
        }
    }
}

int main()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
            cin >> a[i][j];
    }
    gen(a[1][1], 1, 1);
    cout << res;
    return 0;
}
