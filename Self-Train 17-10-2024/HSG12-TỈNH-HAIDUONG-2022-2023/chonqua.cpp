#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6;

void sol() {
    int n, m;
    cin >> n >> m;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    int sum = 0;
    int size = n - 1; 
    for (int i = 0; i < m; i++) {
        if (vec[0] >= vec[size]) {  
            sum += vec[0];          
            vec.erase(vec.begin());
        } else {
            sum += vec[size];       
            vec.erase(vec.begin() + size); 
        }
        size--;  
    }

    cout << sum << endl;  
}

int main() {
    sol();
    return 0;
}
