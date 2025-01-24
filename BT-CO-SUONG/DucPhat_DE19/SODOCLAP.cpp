#include <bits/stdc++.h>
#include <chrono>
using namespace std;
#define ll long long

void init(){
    freopen("SODOCLAP.INP", "r", stdin);
    freopen("SODOCLAP.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool doclap(ll n) {
    int freq[10] = {0};
    while (n > 0) {
        int digit = n % 10;
        if (freq[digit] > 0) return false; 
        freq[digit]++;
        n /= 10;
    }
    return true;
}

int main() {
    init();

    auto start = chrono::high_resolution_clock::now();
    ll n;
    cin >> n;
    ll i = n + 1;
    while (!doclap(i)) {
        i++;
    }
    cout << i << endl;
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;

    return 0;
}
