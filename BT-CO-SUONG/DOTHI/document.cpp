/*
        _.-- ,.--.
      .'   .'     /
       @       |'..--------._
     /      \._/              '.
    /  .-.-                     \
   (  /    \                     \
   \      '.                  | #
    \       \   -.           /
     :\       |    )._____.'   \
      "       |   /  \  |  \    )
    Kduckp       |   |./'  :__ \.-'
              '--'
*/
/*
 * Author: Kduckp
 * Generated on: 2025-06-24 08:55:24
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define endl "\n"
#define min(a, b) min((ll)a, (ll)b)
#define max(a, b) max((ll)a, (ll)b)
#define fi first
#define se second
#define si size()
#define all(x) x.begin(), x.end()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ull unsigned long long
#define pb push_back
#define __TOISETHIVOI__ signed main()

const int MOD = 1e9 + 7;
const int INF = 2 * 1e18;

void init() {
  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);
  fast;
}
bool directed = false; // change to true if directed
int Nodes, Edges;
vector<ll> node;
vector<pair<int, int>> edge;
vector<vector<int, int>> a;
void change_undirected() // ma tran ke do thi vo huong
{
    for(int i = 0; i < Edges;i++)
    {
        a[edge[i].first - 1][edge[i].second - 1]++;
        if(!directed)a[edge[i].second - 1][edge[i].first - 1]++:
    }
}

__TOISETHIVOI__ {
    cin>>Nodes>>Edges;
    node.resize(Nodes);
    edge.resize(Edges);
    for(int i = 0; i < Nodes; i++)cin>>node[i];
    for(int i = 0; i < Edges; i++)cin>>edge[i].first>>edge[i].second;


    return 0;
}