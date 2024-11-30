#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define endl "\n"


using namespace std;

int main() {


    int m, n, m1, n1;
    cin >> m >> n >> m1 >> n1;

    // Đọc ma trận A
    vector<vector<int>> A(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    int maxsum = INT_MIN;
    int row = -1, col = -1;
    for (int i = 0; i <= m - m1; i++) {
        for (int j = 0; j <= n - n1; j++) {
            int currsum = 0;
            for (int x = 0; x < m1; x++) {
                for (int y = 0; y < n1; y++) {
                    currsum += A[i + x][j + y];
                }
            }
            if (currsum > maxsum || (currsum == maxsum && (i < row || (i == row && j < col)))) {
                maxsum = currsum;
                row = i + 1; 
                col = j + 1; 
            }
        }
    }
    cout << maxsum << endl;
    cout << row << " " << col << endl;


    return 0;
}
