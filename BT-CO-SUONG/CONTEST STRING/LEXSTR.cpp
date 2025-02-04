#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e3;
int a[30];
char ans[maxn+5];
int n,cnt=0,sum=0;
string s;
signed main() 
{
    cin>>n;
    cin>>s;
    for(int i = 0;i<26;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    int j=0;
    for(int i = 0;i<s.size();i++)
    {
        ans[j]=s[i];
        if(s[i]!='?')
        {
            if (a[s[i]-'a']>0)
            {
                sum-=1;
                a[s[i]-'a']--;
            }
        }
        else cnt++;
        j++;
    }
    if(sum!=cnt)
    {
        cout<<-1;
        return 0;
    }
    int l=0,r=0;
    while(l<s.size() && r<26)
    {
        if(ans[l]!='?') l++;
        else if(a[r]==0) r++;
        else
        {
            ans[l]=r+'a';
            l++;
            a[r]--;
        }
    }
    for(int i = 0;i<s.size();i++) cout<<ans[i];
    return 0;
}
