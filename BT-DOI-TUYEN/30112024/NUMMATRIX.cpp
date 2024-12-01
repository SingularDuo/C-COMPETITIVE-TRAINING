#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main() {
    int n;
    cin >> n;
    int a[101][101] = {0};

    for (int i = 1; i <= n; i++) {
        a[0][i - 1] = i;
    }
    for (int i = 1; i <= n; i++) {
        a[i - 1][0] = i;
    }

    for (int i = 1; i <= n; i++) {
        int multiply = 1;
        for (int j = 1; j <= n; j++) {
            int value = i * j;
            if (value > n * 2) {
                value = multiply * 2;
                multiply++;
            }
            a[i - 1][j - 1] = value;
        }
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            if(a[i][j] == a[j][i]) continue;
            if(a[i][j] != a[j][i]){
                a[j][i]  = a[i][j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= n; j++) {
            if(i * j > n * 2){
                if(a[i][j+1] - 2 == a[i][j] && i+1 <= n && j +1 <=n){
                    continue;
                }
                else{
                    a[i][j+1] +=2;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
