#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
void init()
{
    freopen("XOACHUSO.inp", "r", stdin);
    freopen("XOACHUSO.out", "w", stdout);
    fast;
}

int maxnumber(int n, int k)
{
    for (int j = 0; j < k; j++) {
 
        int ans = 0;
        int i = 1;
        while (n / i > 0) {
            int temp = (n / (i * 10))* i+ (n % i);
            i *= 10;
            ans = max(ans, temp);
        }
        n = ans;
    }

    return n;
}
int main()
{
    init();
    int n, k;
    cin>>n>>k;

    cout << maxnumber(n, k) << endl;
    return 0;
}