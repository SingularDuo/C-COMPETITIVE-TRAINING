#include <bits/stdc++.h>
using namespace std;
#define int long long
void genperm(int n, int k, vector<int>& current, vector<bool>& used) {
    if (current.size() == k) { 
        for (int num : current) cout << num << " ";
        cout << "\n";
        return;
    }
    
    for (int i = 1; i <= n; i++) {
        if (!used[i]) { 
            used[i] = true;
            current.push_back(i);
            genperm(n, k, current, used);
            current.pop_back();
            used[i] = false;
        }
    }
}

signed main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> current;
    vector<bool> used(n + 1, false); 
    genperm(n, k, current, used);
    
    return 0;
}
