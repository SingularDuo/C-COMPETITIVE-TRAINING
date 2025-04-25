#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int n, m;
        cin >> n >> m; // Number of flowers and requirements

        vector<int> flowers(n);
        for (int i = 0; i < n; i++) {
            cin >> flowers[i]; // Input flower beauties
        }

        vector<int> requirements(m);
        for (int i = 0; i < m; i++) {
            cin >> requirements[i]; // Input beauty requirements
        }

        // Sort both vectors in descending order
        sort(flowers.rbegin(), flowers.rend());
        sort(requirements.rbegin(), requirements.rend());

        int maxBeauty = 0;
        bool possible = true;

        // Try to match requirements
        for (int i = 0; i < m; i++) {
            if (i < n && flowers[i] >= requirements[i]) {
                maxBeauty = max(maxBeauty, flowers[i]);
            } else {
                possible = false;
                break;
            }
        }

        if (possible) {
            cout << maxBeauty << endl;
        } else {
            cout << -1 << endl; // Not possible to fulfill requirements
        }
    }

    return 0;
}
