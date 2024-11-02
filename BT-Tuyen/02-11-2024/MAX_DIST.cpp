#include<bits/stc++.h>
using namespace std;

int main(){
    int t_test;
    cin >> t_test;

    while(t_test--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        
        vetor<int> dd(1e4 + 5, 0);
        vector<int> start(1e4 + 5, -1);
        vector<int> end(1e4 + 5, -1);
        for(int i = 0; i < n; i++) {
            dd[a[i]]++; 
            end[a[i]] = i;

            // gia tri a[i] xuat hien dau tien o vi tri nao
            if(dd[a[i]] == 1) start[a[i]] = i;
        }

        vector<pair<int, int>> b;
    }
}