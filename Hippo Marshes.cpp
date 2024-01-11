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
#define ll long long
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> paths1(n+1);
    vector<vector<int>> paths2(n+1);
    for (int i =0; i<m; i++){
        int a, b;
        cin >> a >> b;
        paths1[a].push_back(b);
        paths2[b].push_back(a);
    }
    vector<int> visitfrom1(n+1);
    vector<int> visitfrom2(n+1);
    queue<int> q1;
    q1.push(1);
    while (!q1.empty()){
        int node = q1.front();
        q1.pop();
        visitfrom1[node] = 1;
        for (auto c : paths1[node]){
            if (!visitfrom1[c]){
                q1.push(c);
            }
        }
    }
    queue<int> q2;
    q2.push(n);
    while (!q2.empty()){
        int node = q2.front();
        q2.pop();
        visitfrom2[node] = 1;
        for (auto c : paths2[node]){
            if (!visitfrom2[c]){
                q2.push(c);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        if (visitfrom1[i] && visitfrom2[i]){
            ans++;
        }
    }
    cout << ans;
 
}
