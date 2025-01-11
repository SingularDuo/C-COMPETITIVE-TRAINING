#include<bits/stdc++.h>
using namespace std;

int main() {
    long long a[3][3]; 
    map<long long, int> luu; 
    long long val = 0;
    for (int i = 0; i < 3; i++) {
        long long curr = 0;
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
            curr += a[i][j];       
            luu[a[i][j]]++;         
        }
        if (i == 0) {
            val = curr; 
        } else if (val != curr) {
            cout << "NO";
            return 0;
        }
    }
    if (luu.size() < 2) {
        cout << "NO";
        return 0;
    }

    for (int j = 0; j < 3; j++) {
        long long current = 0;
        for (int i = 0; i < 3; i++) {
            current += a[i][j];
        }
        if (current != val) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
