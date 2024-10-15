#include<bits/stdc++.h>
using namespace std;
void init(){
    freopen("tienphoto.inp", "r", stdin);
    freopen("tienphoto.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
bool isprime(long long n){
    if(n<=1) return false;
    if(n==2 || n==3) return true;
    if(n%2==0 || n%3==0) return false;
    for(long long i=5; i*i<=n; i++){
        if(n%i==0 || n%(i+2)==0) return false;
    }
    return true;
}
int main() {
    init();
    long long a;
    cin >> a;

    if (isprime(a)) {
        cout << "1";
        return 0;
    }

    long long counts = 0;
    for (long long i = 1; i * i <= a; i++) {
        if (a % i == 0) {
            long long j = a / i;
            if (i < j && j < a) {
                counts++;
            }
        }
    }

    cout << counts;
    return 0;
}
