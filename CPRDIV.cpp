#include <bits/stdc++.h>

using namespace std;
const long long maxn=1e6+5;
long long a[maxn];
long long p[maxn];
bool scp(long long x)
{
    long long k=sqrt(x);
    if(sqrt(x)==k) return true;
    return false;
}
void sieve()
{
    for(long long i=1;i<=maxn;i++)
    {
        p[i]=1;
    }
    p[0]=p[1]=0;
    for(long long i=2;i<=maxn;i++)
    {
        if(p[i]==1)
        {
            for(long long j=2*i;j<=maxn;j+=i)
            {
                if(p[j]==1)
                {
                    p[j]=0;
                }
            }
        }
    }
}
int main()
{
    sieve();
    long long m,n,cnt=0,k;
    cin>>n>>m;
    for(long long i=1;i<=maxn;i++)
    {
        a[i]=0;
    }
    for(long long i=2;i<=n;i++)
    {
        for(long long j=1;j<=sqrt(i);j++)
        {
            if(i%j==0&&j!=1)
            {
                k=i;
                while(k%j==0)
                {
                    a[j]++;
                    k/=j;
                }
            }
            if(i%(i/j)==0&&(i/j)!=1)
            {
                k=i;
                while(k%(i/j)==0)
                {
                    a[i/j]++;
                    k/=(i/j);
                }
            }
        }
        if(scp(i))
        {
            long long t=sqrt(i);
            a[t]-=2;
        }
    }
    for(long long i=2;i<=m;i++)
    {
        for(long long j=1;j<=sqrt(i);j++)
        {
            if(i%j==0&&j!=1)
            {
                k=i;
                while(k%j==0)
                {
                    a[j]--;
                    k/=j;
                }
            }
            if(i%(i/j)==0&&(i/j)!=1)
            {
                k=i;
                while(k%(i/j)==0)
                {
                    a[i/j]--;
                    k/=(i/j);
                }
            }
        }
        if(scp(i))
        {
            long long t=sqrt(i);
            a[t]+=2;
        }
    }
    for(long long i=2;i<=n-m;i++)
    {
        for(long long j=1;j<=sqrt(i);j++)
        {
            if(i%j==0&&j!=1)
            {
                k=i;
                while(k%j==0)
                {
                    a[j]--;
                    k/=j;
                }
            }
            if(i%(i/j)==0&&(i/j)!=1)
            {
                k=i;
                while(k%(i/j)==0)
                {
                    a[i/j]--;
                    k/=(i/j);
                }
            }
        }
        if(scp(i))
        {
            long long t=sqrt(i);
            a[t]+=2;
        }
    }

    for(long long i=1;i<=maxn;i++)
    {
        if(a[i]>0&&p[i])
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
