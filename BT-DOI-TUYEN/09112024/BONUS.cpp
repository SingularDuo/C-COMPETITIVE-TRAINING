#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5;
long long curr;
int a[maxn + 5], cnt = 0, n, b, d;

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a+n+1);
    for (int i = 1; i <= n; i++){
        curr = a[i] + n;
        cnt++;
        d = n;
        for (int j = i; j <= n; j++){
            d--;
            if (i == j) j++;
            if (curr < (a[j] + d)){
                cnt--;
                break;
            }
        }
    }
    cout << cnt;
    return 0;
}