#include <iostream>
#include <fstream>
#include <vector>
#include <limits.h>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    bool found = false;
    for (int i = 0; i < m; ++i) {
        int currmax = INT_MIN;
        int b = -1;
        for (int j = 0; j < n; ++j) {
            if (a[i][j] > currmax) {
                currmax = a[i][j];
                b = j;
            }
        }

        bool yenngua = true;
        for (int k = 0; k < m; ++k) {
            if (a[k][b] < currmax) {
                yenngua = false;
                break;
            }
        }

        if (yenngua) {
            cout << i + 1 << " " << b + 1 << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << 0 << endl;
    }


    return 0;
}
