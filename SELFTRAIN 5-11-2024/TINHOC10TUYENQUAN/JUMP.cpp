#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int findMaxJumpLength(const vector<int>& A, int N, int P) {
    int maxJumpLength = 0;

    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (A[j] - A[i] >= P) {
                maxJumpLength = max(maxJumpLength, j - i);
            }
        }
    }
    return maxJumpLength;
}

int main() {
    int n, p;
    cin>>n>>p;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    int maxJumpLength = findMaxJumpLength(a,n,p);
    cout << maxJumpLength << endl;
    return 0;
}
