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
 * Generated on: 2025-05-17 22:41:06
*/

#include <bits/stdc++.h>
using namespace std;

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

__TOISETHIVOI__ {
    //init();
    int testCases;
    cin >> testCases;
    while (testCases--) {
        int elements;
        cin >> elements;
        vector<int> numbers(elements + 1);
        for (int index = 1; index <= elements; index++) {
            cin >> numbers[index];
        }
        int edgeCount = elements - 1;
        vector<vector<int>> adjacencyList(edgeCount + 1);
        vector<pair<int, bool>> markedNodes;
        for (int index = 1; index <= elements; index++) {
            if (numbers[index] == 0) {
                if (index > 1) markedNodes.emplace_back(index - 1, true);
                if (index < elements) markedNodes.emplace_back(index, false);
            } else {
                if (index == 1) {
                    markedNodes.emplace_back(1, true);
                } else if (index == elements) {
                    markedNodes.emplace_back(elements - 1, false);
                } else {
                    adjacencyList[index - 1].push_back(index);
                }
            }
        }
        vector<int> nodeStatus(edgeCount + 1, -1);
        deque<pair<int, bool>> processingQueue;
        for (auto &node : markedNodes) processingQueue.push_back(node);
        bool contradiction = false;
        while (!processingQueue.empty() && !contradiction) {
            auto currentNode = processingQueue.front();
            processingQueue.pop_front();
            int vertex = currentNode.first;
            bool flag = currentNode.second;
            if (nodeStatus[vertex] != -1) {
                if (nodeStatus[vertex] != (flag ? 1 : 0)) contradiction = true;
                continue;
            }
            nodeStatus[vertex] = flag ? 1 : 0;
            if (flag) {
                for (int neighbor : adjacencyList[vertex]) {
                    processingQueue.emplace_back(neighbor, true);
                }
            }
        }
        cout << (contradiction ? "YES\n" : "NO\n");
    }
    return 0;
}
