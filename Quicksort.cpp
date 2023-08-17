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
#define speed()                  \
    ios::sync_with_stdio(false); \
    cin.tie(0)
#define file(name)                       \
    speed();                             \
    freopen(#name "in.txt", "r", stdin); \
    freopen(#name "out.txt", "w", stdout)
#define dbg(x) cout << '>' << #x << ':' << x << endl;
using namespace std;
vector<vector<int>> v;
vector<int> visited;
void dfs(int node){
    visited[node] = 1;
    for (auto c : v[node]){
        if (!visited[c]){
            dfs(c);
        }
    }
}
int main()
{
    file(qsort);
    int n; cin >> n;
    v.resize(n+2);
    visited.resize(n+2);
    int x;
    int y;
    for (int i = 1; i <= n; i++){
        cin >> x;
        if (x == 1){
            v[i].push_back(i+1);
            continue;
        }
        if (x == 2){
            cin >> x;
            v[i].push_back(x);
            continue;
        }
        if (x == 3){
            cin >> x >> y;
            v[i].push_back(x);
            v[i].push_back(y);
            continue;
        }
    }
    dfs(1);
    int ans = 0;
    for (int i = 1; i <= n; i++){
        if (visited[i]){
            ans++;
        }
    }
    cout << n-ans;

}
