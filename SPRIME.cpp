#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e7;
bool prime[maxn + 5];

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
bool checkdb(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum % 5 == 0;
}

void sol() {
    Sang();
    int t;
    cin >> t;
    while (t--) { 
        int l, r;
        cin >> l >> r;
        int cnt = 0; 
        for (int i = l; i <= r; i++) {
            if(prime[i]){
                if (checkdb(i)) {
                    cnt++;
                }
            }
            
        }
        cout << cnt << endl;
    }
}

int main() {
    sol();
    return 0;
}
