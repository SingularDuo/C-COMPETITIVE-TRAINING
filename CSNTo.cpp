#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e7;
bool prime[maxn + 5];
void Sang()
{
    for (int i = 2; i<= maxn; i++) prime[i] = 1;
    int m = sqrt(maxn);
    for (int i = 2; i<= m; i++)
        if (prime[i] == 1)
        {
            for (int j = i*i; j <= maxn; j+= i) prime[j]= 0;
        }
}

void sol(){
    Sang();
    int k, a, b, counts = 0; 
    cin>>k>>a>>b;
    for(int i = a; i <= b; i++){
        if(prime[i]){
            int n = i;
            int dem = 0;
            while(n > 0){
                n /= 10;
                dem++;
            }
            if(dem == k){
                counts++;
            }
        }
    }
    cout<<counts;
}

int main(){
    sol();
    return 0;
}
