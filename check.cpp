#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("Congsl.inp","r",stdin);
    //freopen("Congsl.out","w",stdout);
    long long x,y;
    string a,b,s,s1;
    getline(cin,a);
    getline(cin,b);
    long long n=max(a.size(),b.size()),flag=0;
    while(a.size()<n){
        a="0"+a;
        //cout<<a<<" "<<n<<" "<<a.size()<<'\n';
    }
    while(b.size()<n){
        b="0"+b;
        //cout<<b<<" "<<n<<" "<<b.size()<<'\n';
    }
    for(long long i=n-1;i>=0;--i){
        x=a[i]-48;
        y=b[i]-48;
        long long k=x+y;
        s1=to_string((k+flag)%10);
        s=s+s1;
        flag=0;
        if(k>9){
            flag=1;
        }
    }

    reverse(s.begin(),s.end());
    cout<<s<<'\n';
    return 0;
}