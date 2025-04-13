#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        if(k == 1)
        {
            cout<<"YES"<<endl;
            continue;
        }
        if(k % 2 == 0)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}
