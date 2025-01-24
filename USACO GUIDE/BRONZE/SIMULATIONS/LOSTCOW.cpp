#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init(){
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void sol() {
    ll res = 0, x, y, start = 1, last;
    cin >> x >> y;
    ll current = x; 
    bool add = true;
    while (true) {
        ll next;
        if (add) {
            next = x + start; 
        } else {
            next = x - start; 
        }
        if ((y >= current && y <= next) || (y <= current && y >= next)) {
            res += abs(current - y); 
            break;
        } else {
            res += abs(current - next);
            current = next; 
            start *= 2; 
            add = !add; 
        }
    }

    cout << res << endl;
}

int main() {
    init();
    sol();
    return 0;
}
