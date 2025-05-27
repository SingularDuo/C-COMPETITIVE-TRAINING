#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"
#define int long long

signed main()
{
    int n;
    cin >> n;
    int am = n;
    int sum = (n + 1) * am / 2;

    if (sum % 2 != 0)
    {
        cout << "NO";
        return 0;
    }

    vector<bool> visited(n + 1, false);
    vector<ll> left, right;
    ll maxx = n;
    int sum1 = 0;

    while (sum1 < sum / 2)
    {
        ll rem = sum / 2 - sum1;

        if (rem > maxx)
        {
            left.push_back(maxx);
            visited[maxx] = true;
            sum1 += maxx;
            maxx--;
        }
        else
        {
            left.push_back(rem);
            visited[rem] = true;
            sum1 = sum / 2;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i]) right.push_back(i);
    }

    cout << "YES" << endl;
    cout << left.size() << endl;
    for (auto &i : left) cout << i << " ";
    cout << endl;
    cout << right.size() << endl;
    for (auto &i : right) cout << i << " ";

    return 0;
}
