#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int binarySearch(const string& str, char target) {
    int left = 0;
    int right = str.length() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (str[mid] == target) {
            return mid;
        }
        else if (str[mid] > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return -1;
}

void sol() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for(int i = alphabet.size(); i >= 0; i++){
        int idx1 = binarySearch(s1, alphabet[i]);
        int idx2 = binarySearch(s2, alphabet[i]);
        if(idx1 == -1 || idx2 == -1)continue;
        else{
            cout<<alphabet[i];
            return;
        }
    }
}

int main() {
    sol();
    return 0;
}
