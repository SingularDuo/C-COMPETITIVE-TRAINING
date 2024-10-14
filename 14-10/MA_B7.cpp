#include <bits/stdc++.h>

using namespace std;
const long long maxn=1e6+5;
long long a[maxn];
int main()
{
    freopen("MA_B7.inp","r",stdin);
    freopen("MA_B7.out","w",stdout);
    for(long long i=2;i<=maxn;i++)
    {
        a[i]=0;
    }
    long long n,x=2,c=1,b=1;
    cin>>n;
    while(n>1)
    {
        if(n%x==0)
        {
            while(n%x==0)
            {
                a[x]++;
                n/=x;
            }
        }
        x++;
    }
    for(long long i=2;i<=x;i++)
    {
        if(a[i]>0)
        {
            if(a[i]%2==0)
            {
                b*=pow(i,a[i]/2);
            }
            else
            {
                c=c*i;
                b*=pow(i,(a[i]-1)/2);
            }
        }
    }
    cout<<b<<" "<<c;
    return 0;
}
