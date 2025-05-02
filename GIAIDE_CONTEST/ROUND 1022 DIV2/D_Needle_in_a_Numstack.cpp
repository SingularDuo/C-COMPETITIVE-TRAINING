#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t; // Read number of test cases

    while (t--) {
        int n, k;
        cin >> n >> k; // Read n and k for each test case

        vector<int> values(n + 1);
        set<int> uniqueValues;

        // Query the first 2k elements to gather information
        for (int i = 1; i <= 2 * k; ++i) {
            cout << "? " << i << endl;
            cout.flush(); // Flush the output buffer

            cin >> values[i]; // Read the response
            uniqueValues.insert(values[i]); // Insert into the set of unique values

            // If we have seen k unique values, we can determine lengths
            if (uniqueValues.size() == k) {
                // We can determine the lengths of A and B
                int a_length = i - k; // Length of A
                int b_length = n - a_length; // Length of B

                // Check if lengths are valid
                if (a_length >= k && b_length >= k) {
                    cout << "! " << a_length << " " << b_length << endl;
                } else {
                    cout << "! -1" << endl;
                }
                break;
            }
        }

        // If we have not determined lengths yet, we need to check further
        if (uniqueValues.size() < k) {
            // We need to check the last k elements to confirm
            for (int i = n - k + 1; i <= n; ++i) {
                cout << "? " << i << endl;
                cout.flush(); // Flush the output buffer

                cin >> values[i]; // Read the response
                uniqueValues.insert(values[i]); // Insert into the set of unique values

                // If we have seen k unique values, we can determine lengths
                if (uniqueValues.size() == k) {
                    int a_length = n - (i - k + 1); // Length of A
                    int b_length = n - a_length; // Length of B

                    // Check if lengths are valid
                    if (a_length >= k && b_length >= k) {
                        cout << "! " << a_length << " " << b_length << endl;
                    } else {
                        cout << "! -1" << endl;
                    }
                    break;
                }
            }
        }

        // If we still cannot determine lengths, we report -1
        if (uniqueValues.size() < k) {
            cout << "! -1" << endl; // Not enough unique values to determine lengths
        }
    }

    return 0;
}x