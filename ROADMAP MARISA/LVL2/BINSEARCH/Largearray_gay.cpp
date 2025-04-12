#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
   ll n, k;
   cin>>n>>k;
   vector<ll> a(n), f(n);
   for(int i = 0; i < n; i++)
   {
       if(i == 0)
       {
           cin>>a[i];
           f[i]  =a[i];
           continue;
       }
       cin>>a[i];
       f[i] = f[i-1] + a[i];
   }
   ll res = 0;
   for(int i = 0; i < n; i++)
   {
	int jres = -1;
       for(int j = i + 1; j < n; j++)
       {
           ll val;
           if(i == 0)val = f[j];
           else val = f[j] - f[i-1];
           if(val >= k)
           {

               jres = j;
               break;
           }
       }


	// update res with jres
        if(jres != -1)res = res + n - jres;

   }
   cout<<res;
}
