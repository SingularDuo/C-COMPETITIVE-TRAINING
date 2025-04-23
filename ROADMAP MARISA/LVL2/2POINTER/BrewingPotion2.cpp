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
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    //for(auto& i : a)cout<<i<<" ";
    cout<<endl;
    /*
    6
    1 2 5 7 9 10
    
    maxx = 4
    res = 1
    res = 1 2
    res = 1 2 5
    res = 1 2 5 7
    res = 2 5 7
    res = 5 7 9
    res = 5 7 9 10
    */
   /// **thay vi su dung queue va pop(), co the tao them 1 con tro danh dau de xac dinh xem thg kia con song ko**
   /// **thay vi push vo queue, co the su dung them con tro thu 2 de danh dau la queue dang push den phan tu do**
    ll idx = 0, j = 0;
    queue<ll> res;
    //cout<<"push "<<a[0]<<endl;
    res.push(a[0]);  
    int maxx = LLONG_MIN;
    for (int i = 1; i < n; i++)
    {
        if (a[i] <= res.front() + k)
        {
            res.push(a[i]);  
            //cout<<"push "<<a[i]<<endl;
            maxx = max(maxx, (int)res.size());
        }
        else
        {
            while (!res.empty()&&res.front() + k < a[i])
            {
                //cout<<"pop "<<res.front()<<endl;
                res.pop();
            }
            //cout<<"push "<<a[i]<<endl;
            res.push(a[i]);  
            maxx = max(maxx, (int)res.size());
        }
    }
    cout << maxx;
}
