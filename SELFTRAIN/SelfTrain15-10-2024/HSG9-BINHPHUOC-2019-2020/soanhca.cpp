#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init(){
    freopen("soanhca.inp", "r", stdin);
    freopen("soanhca.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main()
{
    init();
    string n;
    getline(cin, n);
    sort(n.rbegin(), n.rend());
    cout<<n;
}
