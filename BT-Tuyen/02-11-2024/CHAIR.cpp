#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "/n"
int main()
{
    int n;
    cin>>n;
    vector<int> xich(n);
    for(int i =0 ; i < n; i++)cin>>xich[i];
    if(n == 2)
    {
        cout<<"1";
        return 0;
    }
    else{
        sort(xich.begin(), xich.end());
        for(int i = 0; i < n; i++){
            if(xich[i] == n -2){
                cout<<xich[i];
                return 0;
            }
        }
        cout<<n-2+1;
    }

}
/**
 * 3
 * 3 2 3
 */