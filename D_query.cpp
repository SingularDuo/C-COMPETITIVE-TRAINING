#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
int compute[38];
void precompute()
{
    compute[0] = 1;
    for(int i = 1; i <= 37; i++)
    {
        compute[i] = pow(3, i);
    }
}
int res = 0;
void gen(int n, int idx, int sum)
{
    if(res == 1)return;
    if(sum > n)return;
    if(sum == n)
    {
        res = 1;
        return;
    }
    for(int i = idx; i <= 37; i++)
    {
        gen(n, i+1, sum + compute[i]);
    }
}
signed main()
{
    precompute();
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        gen(n, 0, 0);
        if(res == 1)
        {
            cout<<"TRUE"<<endl;
            res = 0;
            continue;
        }
        else{
            cout<<"FALSE"<<endl;
            res = 0;
            continue;
        }
    }
}


