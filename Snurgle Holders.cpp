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
    freopen(#name ".in", "r", stdin); \
    freopen(#name ".out", "w", stdout)
#define dbg(x) cout << '>' << #x << ':' << x << endl;
using namespace std;


vector<vector<int>> adj;
pair<int, int> solve(int node){
    // maximum inspectors if placed on this node, maximum if not placed
    if (adj[node].empty()){
        return {1, 0};
    }
    int placed = 1;
    int notplaced = 0;
    for (auto i : adj[node]){
        pair<int, int> temp = solve(i);
        placed += temp.second;
        notplaced += max(temp.first, temp.second);
    }
    return {placed, notplaced};
}
int main() {
    file(snurgle);
    int n; cin >> n;
    adj.resize(n+1);
    for (int i = 0; i < n-1; i++){
        int x; cin >> x;
        adj[x].push_back(i+1);
    }
    cout << max(solve(n).first, solve(n).second);
    return 0;
}
