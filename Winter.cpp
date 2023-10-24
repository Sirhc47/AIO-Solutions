#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <climits>
#include <string>
#define speed() \
    ios::sync_with_stdio(false); \
    cin.tie(0)
#define file(name) \
    speed(); \
    freopen(#name "in.txt", "r", stdin); \
    freopen(#name "out.txt", "w", stdout)
#define dbg(x) cout << '>' << #x << ':' << x << endl;
using namespace std;
vector<int> p;
vector<vector<int>> graph;
vector<int> visited;
long long ans = -100005;
long long solve(int node){
    visited[node] = 1;
    long long cost = p[node];
    for (auto c : graph[node]){
        if (visited[c] != 1){
            cost += max(solve(c), 0ll);
        }
    }
    ans = max(ans, cost);
    //cout << "Node: " << node << " cost: " << cost << endl;
    return cost;
}


int main() {
    speed();
    int n;
    cin >> n;
    p.resize(n+1);
    for (int i = 1; i <= n; i++){
        cin >> p[i];
    }
    graph.resize(n+1);
    visited.resize(n+1, 0);
    for (int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    solve(1);
    cout << ans;


    return 0;
}
