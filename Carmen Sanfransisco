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
int main()
{
    file(where);
    int n, m;
    cin >> n >> m;
    vector<bool> cities(n+1, 1);
    map<int, vector<pair<int,int>>> travel;
    int a, b, c;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        travel[a].push_back(make_pair(c, b));
        travel[b].push_back(make_pair(c, a));
    }
    int k;
    int method;
    cin >> k;
    for (int i = 0; i < k; i++){
        vector<bool> newcities(n + 1, 0);
        cin >> method;
        for (int j = 1; j <=n; j++){
            if (cities[j]){
                //dbg(j);
                for (auto c : travel[j]){
                    if (c.first == method){
                        newcities[c.second] = 1;
                    }
                }
            }
        }
        cities = newcities;
    }

    int count = 0;
    for (int i = 1; i <= n; i++){
        if (cities[i]){
            cout << i << "\n";
            count++;
        }
    }
    if (count == 0){
        cout << "Impossible";
    }
}
