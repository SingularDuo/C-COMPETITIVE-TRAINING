#include<bits/stdc++.h>
using namespace std;

int randInt(int l, int r){
    return l + rand() % (r - l + 1);
}

int main(){
    srand(time(NULL)); // reset random seed
    freopen("input.txt", "w", stdout);

    int min_n = 1, max_n = 1000;
    int min_m = 1, max_m = 1000;
    int min_a = -1e9, max_a = 1e9;

    int n = randInt(min_n, max_n);
    int m = randInt(min_m, max_m);

    cout << n << " " << m << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int k = randInt(min_a, max_a);
            cout << k << " ";
        }
        cout << endl;
    }
}
