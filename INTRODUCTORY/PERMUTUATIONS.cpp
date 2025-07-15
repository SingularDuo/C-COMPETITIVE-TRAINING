#include <bits/stdc++.h>

using namespace std;

void permutation(int N)
{
    if (N == 2 || N == 3) {
        cout << "NO SOLUTION\n";
        return;
    }
    for (int i = 2; i <= N; i = i + 2) {
        cout << i << " ";
    }
    for (int i = 1; i <= N; i = i + 2) {
        cout << i << " ";
    }
}

int main()
{
    int n; cin>>n;
    permutation(n);
}
