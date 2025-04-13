#include<bits/stdc++.h>
using namespace std;


#define ll long long


const int MOD = 1e9 + 7;


struct HCN{
   int x1, y1;
   int x2, y2;


   bool is_valid() {
       return x1 <= x2 && y1 <= y2;
   }


   ll get_area() {
       return 1ll * (x2 - x1) * (y2 - y1);
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


ll sum_area[205];


int main() {
   int n; cin >> n;
   for(int i = 0; i < n; i++) {
       cin >> rectangles[i].x1 >> rectangles[i].y1;
       cin >> rectangles[i].x2 >> rectangles[i].y2;
   }


   // n hcn --> n bit
   // min: 000...000 => 0
   // max: 111...111 + 1 => 100000000000 (1 số 1 và n số 0) => 2^n
   // max: 2^n - 1


   ll ans = 0;
   for(int mask = 0; mask < (1 << n); mask++){
       vector<HCN> hcn_chosen;
       for(int bit = 0; bit < n; bit++) {
           int val = get_bit(mask, bit);
           if(val == 1) hcn_chosen.push_back(rectangles[bit]);
       }


       HCN result = giao_nhau_list(hcn_chosen);
       if(result.is_valid()) {
           ll area = result.get_area();


           int sz = hcn_chosen.size();
           // if(sz & 1) ans += area;
           // else ans -= area;
           sum_area[sz] += area;
       }
   }


   ans = 0;
   for(int i = 1; i <= n; i++) {
       if(i % 2) ans += sum_area[i];
       else ans -= sum_area[i];
      
       ans = (ans + MOD) % MOD;
   }
   cout << ans << endl;
}
