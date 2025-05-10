#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define endl "\n"
#define min(a,b) min((ll)a, (ll)b)
#define max(a,b) max((ll)a, (ll)b)

signed main()
{
    int n;
    cin>>n;
    // +3 lien tuc tu 2
    // nhan xet: voi moi lan boc, thi cac so se cach nhau them 3^luot boc
    // so bat dau se la so dau tien o luot truoc + 3^(luot boc - 1) ==> la so thu 2 cua day trc do
    //  
    int add = 3;
    int start_index = 2;
    vector<ll> a(n, 0);
    vector<ll> sub;
    for(int i  = start_index; i <= n; i+=add)
    {
        sub.push_back(i);
    }
    start_index--;
    while(sub.size() > 1)
    {
        vector<ll> curr;
        for(int i = start_index; i <= sub.size(); i+=add)
        {
            //cout<<i<<" "<<sub[i]<<endl;
            curr.push_back(sub[i]);
        }
        sub = curr;
    }
    cout<<sub[0];

}