#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
struct HCN
{
    int x1,y1;
    int x2,y2;
    bool is_valid()
    {
        return x1 <= x2 && y1<=y2;
    }
    ll get_area()
    {
        return 1ll * (x2-x1+1) * (y2-y1+1);
    }

    void print() {
        printf("HCN: (%lld, %lld), (%lld, %lld)\n", x1, y1, x2, y2);
    }
};
HCN giao_nhau(HCN a, HCN b) {
    HCN ans;
    ans.x1 = max(a.x1, b.x1);
    ans.y1 = max(a.y1, b.y1);
 
 
    ans.x2 = min(a.x2, b.x2);
    ans.y2 = min(a.y2, b.y2);
 
 
    return ans;
}
HCN giao_nhau_list(vector<HCN> rectangles) {
    if(rectangles.empty()) return {0, 0, 0, 0};
 
 
    HCN hcn_giao_nhau = rectangles[0];
    for(int i = 1; i < rectangles.size(); i++) {
        hcn_giao_nhau = giao_nhau(hcn_giao_nhau, rectangles[i]);
        if(!hcn_giao_nhau.is_valid()) {
            return hcn_giao_nhau;
        }
    }
 
 
    return hcn_giao_nhau;
}
 
 
HCN rectangles[205];
 
int get_bit(int mask, int bit) {
    mask = mask / (1 << bit);
    return mask & 1;
}

ll sum[205];
KING_PHAT
{
    fast;

    int n; cin>>n;

    for(int i =0;i < n;i++)
    {
        cin>> rectangles[i].x1 >> rectangles[i].y1;
        //rectangles[i].x1--, rectangles[i].y1--;
        cin>> rectangles[i].x2 >> rectangles[i].y2;
    }
    
    ll ans = 0;
    for(int i = 0; i < (1<<n); i++)
    {
        vector<HCN> lay;
        for(int j = 0; j < n; j++)
        {
            int val = get_bit(i, j);
            if(val == 1)lay.push_back(rectangles[j]);
        }
        HCN result = giao_nhau_list(lay);

        if(result.is_valid())
        {
            ll area = result.get_area();
            int ss = lay.size();
            sum [ss] = area;
        }
    }

    HCN rect_ans = giao_nhau(rectangles[0], rectangles[1]);
    rect_ans.print(); 

    ans = 0;
    for(int i = 1; i <= n; i++) {
        if(i % 2) ans += sum[i];
        else ans -= sum[i];
        
        
    }
    cout<<ans<<endl;

}