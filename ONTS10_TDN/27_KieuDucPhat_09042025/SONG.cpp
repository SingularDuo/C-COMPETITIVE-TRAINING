#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("SONG.inp", "r", stdin);
    freopen("SONG.out", "w", stdout);
    vector<int> notes(8);
    for (int i = 0; i < 8; ++i) {
        cin >> notes[i];
    }

    bool ascending = true, descending = true;

    for (int i = 1; i < 8; ++i) {
        if (notes[i] > notes[i - 1]) {
            descending = false;
        } else if (notes[i] < notes[i - 1]) {
            ascending = false;
        }
    }

    if (ascending) {
        cout << "ASCENDING" << endl;
    } else if (descending) {
        cout << "DESCENDING" << endl;
    } else {
        cout << "MIXED" << endl;
    }

    return 0;
}
