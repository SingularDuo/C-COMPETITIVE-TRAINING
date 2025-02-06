#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll n, f[100005][30], t[30], dem = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    n = s.size();
    s = " " + s;
    for(int i = 1; i <= n; i++) s[i] = s[i] - 'a' + 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 26; j++) if (s[i] == j) f[i][j] = f[i - 1][j] + 1;
        else f[i][j] = f[i - 1][j];
    }
    for(int i = 1; i <= n; i++) t[s[i]] = n + 1;
    for (int i = n; i >= 1; i--){
        if (t[s[i]] > i)
            dem += t[s[i]] - i - 1;
        for(int j = 1; j <= 26; j++) if (j != s[i])
        {
            ll k = min(t[s[i]], n);
            if (f[k][j] - f[i][j] > 1)
                dem -= (f[k][j] - f[i][j] - 1);
        }
        t[s[i]] = i;
    }
    cout << dem;
}
/*
f[i][j] la so lan xuat hien cua ki tu j tinh den vi tri i
*/