#include <iostream>
#include <vector>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

void sol() {
    vector<vector<int>> a(5, vector<int>(5, 0));
    int x1, y1;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                x1 = i + 1; 
                y1 = j + 1;
            }
        }
    }

    cout << abs(x1 - 3) + abs(y1 - 3) << endl;
}

int main() {
    fast;
    sol();
    return 0;
}
