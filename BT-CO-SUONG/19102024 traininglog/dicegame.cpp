#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<pair<int, int>> vec1(2); 
    vector<pair<int, int>> vec2(2); 

    for (int i = 0; i < 2; i++) { 
        cin >> vec1[i].first >> vec1[i].second;
    }
    for (int i = 0; i < 2; i++) { 
        cin >> vec2[i].first >> vec2[i].second;
    }
    double sumTi = 0, sumSiu = 0;

    for (int i = 0; i < 2; i++) {
        sumTi += (vec1[i].first + vec1[i].second) / 2.0;
        sumSiu += (vec2[i].first + vec2[i].second) / 2.0;
    }
    if (sumTi > sumSiu) cout << "1"; 
    else if (sumTi < sumSiu) cout << "2"; 
    else cout << "3"; // Tie
}
