#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

void queryType1(int k, vector<int>& nodes) {
    cout << "? 1 " << k;
    for (int i = 0; i < k; ++i) {
        cout << " " << nodes[i];
    }
    cout << endl;
    cout.flush();
}

void queryType2(int u) {
    cout << "? 2 " << u << endl;
    cout.flush();
}

int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int n;
        cin >> n; // Size of the tree
        vector<pair<int, int>> edges(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            cin >> edges[i].first >> edges[i].second; // Read edges
        }

        // Assuming node 1 is the root for simplicity
        vector<int> nodes(n);
        for (int i = 1; i <= n; ++i) {
            nodes[i - 1] = i; // Fill nodes with their indices
        }

        // Query the sum of values from root to all nodes
        int sum = 0;
        queryType1(n, nodes);
        cin >> sum; // Read the response from the jury

        // Example of toggling a node's value
        // This is just a placeholder; you would implement your logic here
        for (int i = 1; i <= n; ++i) {
            queryType2(i); // Toggle each node
        }

        // Output the final values of the nodes
        cout << "! ";
        for (int i = 1; i <= n; ++i) {
            cout << (i % 2 == 0 ? 1 : -1) << " "; // Example output
        }
        cout << endl;
        cout.flush();
    }
    return 0;
}