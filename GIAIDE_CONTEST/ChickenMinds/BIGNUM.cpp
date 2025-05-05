#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl "\n"
#define max(a,b) max((ll)a, (ll)b)
#define min(a,b) min((ll)a, (ll)b)
#define si size()
signed main()
{
    string s;
    cin>>s;
    int k;
    cin>>k;
    int to_delete = (ll)s.size() - k;
    for(int i = 0; i < s.si; i++)
    {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            to_delete--;
            s.erase(i, 1);
            i--; 
        }
        if(to_delete <= 0) break;
    }
    
    if(to_delete == 0)
    {
        // doan nay a ko chac de bai nhu the nao nen hen xui e nhe
        cout<<s;
        return 0;
    }
    // 100% den day thi  het chu cai r ==> 1 string toan so
    string result = "";
    for (char c : s) {
        while (!result.empty() && result.back() < c && to_delete > 0) {
            result.pop_back();
            to_delete--;
        }
        result.push_back(c);
    }
    
    
    cout<<result;
    return 0;
}
