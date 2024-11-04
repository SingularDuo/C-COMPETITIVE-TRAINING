#include <bits/stdc++.h>
using namespace std;

int main() {
    //init();
    int n;
    cin >> n;
    vector<int> vec;
    while (n > 0) {
        int a = n % 16;
        vec.push_back(a);
        n /= 16;
    }
    for (int i = vec.size() - 1; i >= 0; i--) {
        if (vec[i] < 10) {
            cout << vec[i];
        } else {
            cout << char('A' + vec[i] - 10);
        }
    }
    cout << endl;
    return 0;
}
