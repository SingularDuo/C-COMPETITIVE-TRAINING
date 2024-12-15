#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
int main() {
    ll n;
    cin >> n;
    ll i = 1;
    ll res = 0;
    /*cong thuc lagrange n
    while(n / power(5, i) > 0){
        res += n/power(5,i);
        i++;
    }*/
    while(n > 0){
        res += n/5;
        n /= 5;
    }
    cout<<res;
    return 0;
}
/*
60 / 5 = so luong so chia het cho 5
= 12 ==> co 12 so chia het cho 5 trong khoang 1 -->60
trong 12 so do chac chan se co 2 so chia het cho 5 2 lan
1 x 5 x 5 = 25
2 x 5 x 5 = 50
cu co 5 so chia het cho 5 1 lan thi se xuat hien 1 so chia het cho 5 2 lan 25->50->75
==> phep tinh 12 / 5 =  so luong so chia het cho 5 nhieu hon so lan truoc do
tiep tuc voi 5 ^ 3, ^4, .....

*/