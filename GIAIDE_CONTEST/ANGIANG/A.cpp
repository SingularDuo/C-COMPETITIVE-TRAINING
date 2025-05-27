#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define square(x) (1ll*(x)*(x))
#define double long long

#define endl "\n"

bool tri(double a, double b, double c) {
    const double EPS = 0; 
    return abs(a + b - c) == EPS || abs(a + c - b) == EPS || abs(b + c - a) == EPS;
}

int main() {
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    double c1_sq = square(x2 - x1 ) + square(y2 - y1 );  
    double c2_sq = square(x3 - x1 ) + square(y3 - y1 );
    double c3_sq = square(x2 - x3 ) + square(y2 - y3 );

    if (tri(c1_sq, c2_sq, c3_sq)) {
        cout << "TAM GIAC VUONG";
    } else {
        cout << "KHONG PHAI TAM GIAC VUONG";
    }

    return 0;
}
