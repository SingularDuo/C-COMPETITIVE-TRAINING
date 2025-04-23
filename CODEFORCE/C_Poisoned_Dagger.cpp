#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define ll unsigned long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
const int maxn = 1e18; // max damage possible

int cal(const vector<int>& a, int k) {
    int sum = 0;
    int endtime = 0;

    for (int i : a) {
        if (i >= endtime) {
            sum += k;
        } else {
            sum += (i + k - endtime);
        }
        endtime = i + k;
    }

    return sum;
}
bool isvalid(vector<int>& a, int k, int h)
{
    //if(k * a.size() < h)return false;
    return cal(a, k) >= h;
}
KING_PHAT
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        int n, h;
        cin>>n>>h;
        vector<int> a(n);
        for(int i = 0; i < n; i++)cin>>a[i];
        int l = 1, r = maxn;
        int res = LLONG_MAX;
        while(l <= r)
        {
            int mid = (l + r)/2;
            if(isvalid(a,mid,h))
            {
                res = min(res, mid);
                r = mid - 1;
            }
            else l = mid + 1;
        }
        cout<<res<<endl;
    }
}