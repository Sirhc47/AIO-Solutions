#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#define speed()                  \
    ios::sync_with_stdio(false); \
    cin.tie(0)
#define file(name)                       \
    speed();                             \
    freopen(#name "in.txt", "r", stdin); \
    freopen(#name "out.txt", "w", stdout)
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<set<int>> edges(n+1);
    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        edges[a].insert(b);
        edges[b].insert(a);
    }
    for (int i = 1; i <= n; i++){
        cout << edges[i].size() << " ";
        for (auto c : edges[i]){
            cout << c << " ";
        }
        cout << "\n";
    }
 
}
