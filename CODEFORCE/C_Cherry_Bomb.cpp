#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define int long long

signed main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        // Check if all elements of b are -1
        bool all_missing = true;
        for (int i = 0; i < n; i++) {
            if (b[i] != -1) {
                all_missing = false;
                break;
            }
        }

        if (all_missing) {
            // Handle case when all elements of b are -1
            sort(a.begin(), a.end());
            int min_val = a[0];
            int max_val = a[n - 1];
            if (max_val == k) {
                cout << (min_val + k - k) << endl;  // Result based on constraints
            } else {
                cout << (min_val + k - a[n - 2]) << endl;  // Result based on sorted a
            }
        } else {
            int required_sum = -1;  // Target sum for complementary arrays
            bool valid = true;

            // Verify sums based on known values in b
            for (int i = 0; i < n; i++) {
                if (b[i] != -1) {
                    int current_sum = a[i] + b[i];
                    if (required_sum == -1) {
                        required_sum = current_sum;
                    } else if (current_sum != required_sum) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid) {
                cout << 0 << endl;
                continue;
            }

            // Validate possible values for -1 in b
            for (int i = 0; i < n; i++) {
                if (b[i] == -1) {
                    int required_b = required_sum - a[i];
                    if (required_b < 0 || required_b > k) {
                        valid = false;
                        break;
                    }
                }
            }
            cout << (valid ? 1 : 0) << endl;  // Output result based on validity
        }
    }

    return 0;
}
