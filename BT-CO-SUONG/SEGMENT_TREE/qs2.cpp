#include <bits/stdc++.h>
const int maxn = 1e5;
int a[maxn];
int t[4*maxn];
using namespace std;
#define endl '\n'
void init()
{
    freopen("QSUM.inp", "r", stdin);
    freopen("QSUM.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void build(int a[], int v, int tl, int tr)
{
    if (tl == tr) {
        t[v] = a[tl];
    	} else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

void update(int v, int tl, int tr, int pos, int new_val)
{
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}


int sum(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}


int main()
{
    //init()
    int n,q;
    cin >>n >> q;
    build(a,1,1,n);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(a,1,1,n);
    while(q--)
    {
        int testt;
        int l,r;
        int pos, newval;
        cin >> testt;
        if(testt == 1)
        {
            cin >> pos >> newval;
            update(1,1,n,pos,newval);
        }
        else if (testt==2)
        {
            cin >> l >> r;
            cout << sum(1,1,n,l,r) << endl;
        }
    }
}