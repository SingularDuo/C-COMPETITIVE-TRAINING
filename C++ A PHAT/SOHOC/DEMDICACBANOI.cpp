#include <iostream>
#include <vector>

using namespace std;

const int MOD = 23;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> count(MOD, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long result = 0;
    
    for (int j = 0; j < n; j++) {
        if (j >= 6) {
            int mod_val = a[j - 6] % MOD;
            count[mod_val]++;
        }
        result += count[a[j] % MOD];
    }

    cout << result << endl;
    return 0;
}
