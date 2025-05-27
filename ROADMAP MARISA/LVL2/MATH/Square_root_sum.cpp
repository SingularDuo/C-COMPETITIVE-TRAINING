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
void sol() {
    int a, b;
    cin >> a >> b;
    
    int start = ceil(sqrt(a)), end = floor(sqrt(b)); 
    int res = 0;
    //cout<<start<<" "<<end<<endl;
    for (int i = a; i < start * start; i++)
        res += floor(sqrt(i));


    for (int i = end * end; i <= b; i++)
        res += floor(sqrt(i));


    vector<long long> squares;
    for (int i = start; i <= end; i++)
        squares.push_back(1LL * i * i);

    for (size_t i = 1; i < squares.size(); i++) {
        long long v = squares[i] - squares[i - 1];
        //cout<<v<<endl;
        v *= floor(sqrt(squares[i-1])); 
        //cout<<v<<endl;
        //cout<<endl;
        res += v;
    }

    cout << res << endl;
}
KING_PHAT
{
    // set state for multitest
    // multitest = true;
    //set state for I/O style
    //I_O("test1", "test1");
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