#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
bool ava = false;
int n, k;
vector<ll> a(n);
void gen(ll idx, ll &currsum)
{
    if(currsum > k)return;
    else if(currsum ==k){
        ava = true;
        return;
    }
    for(int i = idx; i <= n; i++ ){
        int current = a[i];
        currsum+= current;
        gen(i+1, currsum);
        currsum -= current;
    }

}
KING_PHAT
{
    fast;
    
    cin>>n>>k;
    a.resize(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    ll currsum = 0;
    gen(0, currsum);
    if(ava)cout<<"YES";
    else cout<<"NO";
}