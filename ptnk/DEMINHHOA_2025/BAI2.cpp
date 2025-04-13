#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define int long long
const int maxn = 1e6;
int uoc[maxn + 2];

/*
3
8
8 4 25 10 6 6 9 15
5
13 18 1 12 20
7
21 8 5 26 12 34 35
*/

void souoc()
{
    for(int i = 1; i * i <= maxn; i++)
    {
        for (int j = i; j <= maxn / i; j++)
        {
            uoc[i * j] += (1 + (i != j));
        }
    }
}

signed main()
{
    souoc();
    int t;
    cin >> t;
    int maxx = INT_MIN;
    while(t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n + 1);
        vector<ll> cnt(1e6, 0);

        a[0] = LLONG_MIN;
        bool pass = false;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            cnt[uoc[a[i]]]++;
            if(a[i] == a[i - 1]) pass = true;
        }
        if(pass)
        {
            maxx = max(maxx, 0LL);
            continue;
        }
        sort(cnt.begin(), cnt.end(), greater<ll>());
        maxx = max(maxx, cnt[0]);

    }
    cout << maxx;
}
