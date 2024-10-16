#include<bits/stdc++.h>
using namespace std;
void init(){
    freopen("khuvuichoi.inp", "r", stdin);
    freopen("khuvuichoi.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main() {
    init();


    int gbt, gkt;
    cin>> gbt >> gkt;

    int totalHours = gkt - gbt;
    int totalCost = 0;
    for (int hour = gbt; hour < gkt; ++hour) {
        if (hour >= 6 && hour < 12) {
            totalCost += 6;
        } else if (hour >= 12 && hour < 22) {
            totalCost += 10;
        }
    }
    if (totalHours > 4) {
        int discountHours = totalHours - 4;
        int discount = 0;
        for (int i = 0; i < discountHours; ++i) {
            int hour = gbt + 4 + i;

            if (hour >= 6 && hour < 12) {
                discount += 3;
            } else if (hour >= 12 && hour < 22) {
                discount += 5;
            }
        }

        totalCost -= discount;
    }
    cout << totalCost << endl;



    return 0;
}
