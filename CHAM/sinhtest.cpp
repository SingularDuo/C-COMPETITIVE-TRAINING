#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1E18;
int randInt(int l, int r){
    return l + rand() % (r - l + 1);
}

int main(){
    srand(time(NULL)); // reset random seed
    freopen("input.txt", "w", stdout);

    long long min_n = 1, max_n = MOD;

    long long n = randInt(min_n, max_n);

    cout << n << endl;
}
