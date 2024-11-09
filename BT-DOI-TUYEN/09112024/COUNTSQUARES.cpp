#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int n, t;
int a[255];
pair <int, int> currmax;
map <int, int> freq;
int main()
{
    cin >> t;
    while(t--){
        cin >> n;
        currmax.first = currmax.second = -1;
        freq.clear();

        for (int i = 1; i <= n; i++){
            cin >> a[i];
            freq[a[i]]++;
        }

        for (auto i : freq){
            if (i.second >= 4){
                currmax.first = i.first*i.first;
                currmax.second = i.second/4;
            }
        }

        if (currmax.first != -1) cout << currmax.first << " " << currmax.second;
        else cout << -1;
        if (t > 0) cout << '\n';
    }
    return 0;
}