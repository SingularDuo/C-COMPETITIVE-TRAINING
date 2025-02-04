#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main() {
    int n;
    cin >> n;
    cin.ignore(); 

    vector<string> A(n);
    for (int i = 0; i < n; i++) {
        getline(cin, A[i]); 
    }
    string header1 = "Lookattheanimals,dancing,dancing,";
    string header2 = "Lookattheanimals,dancingtothemusic";
    string add = ",dancing, dancing,";
    string comma = ",";
    int cnt = 0;
    ll comma_val = 0;
    ll dancing_val = 0;
    ll head2_val = 0;
    for(char c : add) if(isalpha(c)) dancing_val++;
    for (char c : header2) if (isalpha(c)) head2_val++;
    for(char c : comma) if(isalpha(c)) comma_val ++;
    for (char c : header1) if (isalpha(c)) cnt++;
    cnt += head2_val;
    vector<ll> alpha_sum(n);
    for (int i = 0; i < n; i++) {
        for (char c : A[i]) {
            if (isalpha(c)) alpha_sum[i]++;
        }
    }

    for (int i = 0; i < n; i++) {
        ll line_sum = 0;
        for (int j = i; j >= 0; j--) {
            line_sum += alpha_sum[j];
            if (j < i) line_sum += comma_val;
        }
        if (i > 0) line_sum += 3;
        cnt += line_sum + dancing_val + head2_val;
    }
    cout << cnt << endl;
    return 0;
}
/*
5
one fat cat
two big elephants
three small bats
four long snakes
five thin bears
*/