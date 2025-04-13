#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e7;
bool prime[maxn + 5];
float a, b;
void init()
{
    freopen("MA_B2.inp", "r", stdin);
    freopen("MA_B2.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void Sang()
{
    for (int i = 2; i<= maxn; i++) prime[i] = 1;
    int m = sqrt(maxn);
    for (int i = 2; i<= m; i++)
        if (prime[i] == 1)
        {
            for (int j = i+i; j <= maxn; j+= i) prime[j]= 0;
        }


}

void Sol()
{
   Sang();
   cin >> a>> b;
   int counts = 0;
   for (int i = a; i<= b; i++)
        if (prime[i]== 1) counts ++;
   cout << counts;
}

int main()
{
    init();
    Sol();
    return 0;
}
