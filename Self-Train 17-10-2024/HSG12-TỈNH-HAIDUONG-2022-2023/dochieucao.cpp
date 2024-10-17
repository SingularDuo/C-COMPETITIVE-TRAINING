#include<bits/stdc++.h>

using namespace std;

int main() {
    int a, h;
    double alpha;
    cin >> a;       
    cin >> alpha; 
    cin >> h;     
    double alpha_radian = alpha * M_PI / 180.0;
    double treeHeight = h + a * tan(alpha_radian);
    cout << fixed << setprecision(3) << treeHeight << endl;

    return 0;
}
