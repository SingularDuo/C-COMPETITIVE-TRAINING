#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> chocolates(n);
        for (int i = 0; i < n; ++i) {
            cin >> chocolates[i];
        }
        while (chocolates.size() > 1) {
            if (chocolates.front() > chocolates.back()) {
                chocolates.pop_front();
            } else {
                chocolates.pop_back();
            }
        }

        cout << chocolates.front() << endl;
    }
    return 0;
}
