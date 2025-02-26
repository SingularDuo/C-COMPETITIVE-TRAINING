#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Sort the lucky numbers
    sort(a.begin(), a.end());

    int best_u = 0, best_v = 0;
    int min_diff = numeric_limits<int>::max();
    bool found = false;

    // Iterate through all possible pairs (u, v)
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int current_u = a[i];
            int current_v = a[j];

            // Count how many numbers are in the range [current_u, current_v]
            int count_x = 0;
            for (int k = 0; k < n; ++k) {
                if (a[k] >= current_u && a[k] <= current_v) {
                    count_x++;
                }
            }

            // Count how many numbers are in the range [-current_v, -current_u]
            int count_y = 0;
            for (int k = 0; k < n; ++k) {
                if (a[k] <= -current_u && a[k] >= -current_v) {
                    count_y++;
                }
            }

            // Check if the counts meet the requirements
            if (count_x >= x && count_y >= y) {
                int diff = current_v - current_u;
                if (diff < min_diff || (diff == min_diff && current_u < best_u)) {
                    best_u = current_u;
                    best_v = current_v;
                    min_diff = diff;
                    found = true;
                }
            }
        }
    }

    // Output the result
    if (found) {
        cout << best_u << " " << best_v << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
