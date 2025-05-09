#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define vec(type, a, size, value) vector<type> a(size, value);
#define all(x) x.begin(), x.end()
#define I_O(input_name, output_name) freopen((string(input_name) + ".inp").c_str(), "r", stdin); freopen((string(output_name) + ".out").c_str(), "w", stdout); fast;
#define min(a,b) min((ll)a, (ll)b)
#define max(a,b) max((ll)a, (ll)b)
bool multitest = false;
void init()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    fast;
}
bool DIVN(int x) {
    int sum = 0, digits = 0, temp = x;
    while (temp) {
        sum += temp % 10;
        temp /= 10;
        digits++;
    }
    return sum % digits == 0;
}
void sol()
{
    int k;
    cin>>k;
    int cnt = 1;
    ll i = 1;
    while(cnt < k)
    {
        if(DIVN(i))cnt++;
        i++;
    }
    cout<<i;
    return;
}
KING_PHAT
{
    // set state for multitest
    // multitest = true;
    //set state for I/O style   
    I_O("DIVN", "DIVN");
    fast;
    if (multitest)
    {
        int t;
        cin >> t;
        while (t--)
        {
            sol();
        }
    }
    else
    {
        sol();
    }
    return 0;
}