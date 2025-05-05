#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
//jahduhadhahsd
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, r;
    cin >> n >> r; 

    vector<double> a;
    set<double> cnt; 
    for (int i = 0; i < n; i++)
    {
        double x; 
        cin>>x;
        if(!cnt.count(x))
        {
            a.push_back(x*2);
            cnt.insert(x);
        }
    }
    sort(a.begin(), a.end());

    set<double> value;
    vector<double> possible;
    for (int i = 1; i < a.size(); i++)
    {
        double curr = (a[i] + a[i - 1]) / 2;
        if(!value.count(curr))
        {
            possible.push_back(curr);
            value.insert(curr);
        }

        if (i + 1 < n && abs(a[i] - a[i - 1]) == abs(a[i + 1] - a[i]) && !value.count(abs(a[i])))
        {
            possible.push_back(a[i]);
            value.insert(a[i]);
        } 
    }

    n = a.size();
    ll res = 0;
    for (double point : possible)
    {
        auto it = lower_bound(a.begin(), a.end(), point);
        int start, last;
 
        if (binary_search(a.begin(), a.end(), point)) 
        {
            start = (it - a.begin()) - 1;
            last = (it - a.begin()) + 1;
        }
        else
        {
            start = (it == a.begin()) ? -1 : (it - a.begin() - 1);
            last = (it == a.end()) ? -1 : (it - a.begin());
        }

        while(start > 0 && last < n-1 && abs(a[start] - point) == abs(a[last] - point))
        {
            start--;
            last++;
        }

        if((start == 0 || last == n-1) && (point - a[start] == a[last] - point))
        {
            res++;
            continue;
        }
    }
    cout << res;

    return 0; 
}
