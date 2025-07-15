// can giang lai 
#include <bits/stdc++.h>
using namespace std;
using i128 = __int128_t;


i128 extended_euclid(i128 a, i128 b, i128 &u, i128 &v) {
    if (b == 0) {
        u = 1; v = 0;
        return a;
    }
    i128 u1, v1;
    i128 d = extended_euclid(b, a % b, u1, v1);
    u = v1;
    v = u1 - (a / b) * v1;
    return d;
}

i128 ceil_div(i128 num, i128 den) {
    if (den < 0) num = -num, den = -den;
    if (num >= 0) return (num + den - 1) / den;
    else return num / den;  
}

void print_i128(i128 x) {
    if (x == 0) { 
        cout << '0';
        return;
    }
    if (x < 0) {
        cout << '-';
        x = -x;
    }
    string s;
    while (x > 0) {
        int digit = int(x % 10);
        s.push_back('0' + digit);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i128 A, B, X;
    long long a,b,x_input;
    cin >> a >> b >> x_input;
    A = a; B = b; X = x_input;


    i128 u, v;
    i128 d = extended_euclid(A, B, u, v);


    if (X % d != 0) {
        cout << -1;
        return 0;
    }


    i128 mul = X / d;
    i128 x0 =  u * mul;
    i128 y0 = -v * mul;


    i128 Bd = B / d;
    i128 Ad = A / d;

    i128 k1 = ceil_div(-x0, Bd);
    i128 k2 = ceil_div(-y0, Ad);
    i128 k  = max(k1, k2);

    i128 x = x0 + Bd * k;
    i128 y = y0 + Ad * k;


    print_i128(x + y);
    return 0;
}
