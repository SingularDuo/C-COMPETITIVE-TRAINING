#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl "\n"
#define fi first
#define se second
#define float double
const float limit = 1000000;
signed main()
{
    int a, b;
    cin >> a >> b;

    vector<int> arr = {b, b, 3 * a - 2 * b};

    cout << arr.size() << endl;
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}

