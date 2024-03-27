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
#define ll long long
using namespace std;
ll gcd(ll a, ll b)
{
    if (b > a)
    {
        return gcd(b, a);
    }
    if (b == 0){
        return a;
    }
    return gcd(b, a % b);
    // LCM = (a*b)/gcd(a,b)
}
int t[2000000];
void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}
int sum(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}
const int dx[5] {1, 0, -1, 0, 0}, dy[5]{0, 1, 0, -1, 0};
 
int main()
{
    int n; cin >> n;
    vector<pair<pair<int,int>, int>> islands;
    vector<pair<pair<int,int>, int>> islands2;
    for (int i = 0; i < n; i++){
        int x,y; cin >> x >> y;
        islands.push_back({{x,y}, i});
        islands2.push_back({{y,x}, i});
    }
    //represent as graph
    sort(islands.begin(), islands.end());
    sort(islands2.begin(), islands2.end());
    vector<vector<pair<int,int>>> graph(n);
 
    for (int i = 0; i < n-1; i++){
        if (islands[i].first.first == islands[i+1].first.first){
            graph[islands[i].second].push_back({islands[i+1].second, islands[i+1].first.second-islands[i].first.second});
            graph[islands[i+1].second].push_back({islands[i].second, islands[i+1].first.second-islands[i].first.second});
            //cout << islands[i].second << " " << islands[i+1].second << " " << islands[i+1].first.second-islands[i].first.second << "\n";
        }
        if (islands2[i].first.first == islands2[i+1].first.first){
            graph[islands2[i].second].push_back({islands2[i+1].second, islands2[i+1].first.second-islands2[i].first.second});
            graph[islands2[i + 1].second].push_back({islands2[i].second, islands2[i + 1].first.second - islands2[i].first.second});
            //cout << islands2[i].second << " " << islands2[i + 1].second << " " << islands2[i+1].first.second - islands2[i].first.second << "\n";
        }
    } 
    //run dijkstras
    vector<ll> distances(n, 99999999999);
    distances[0] = 0;
    priority_queue<pair<ll, int>> pq;
    pq.push({0, 0});
    vector<int> visited(n, 0);
    while (!pq.empty()){
        int v = pq.top().second;
/*         dbg(v);
        dbg(distances[v]); */
        pq.pop();
        if (visited[v]){
            continue;
        }
        visited[v] = 1;
        for (auto c : graph[v]){
            if (distances[v]+c.second < distances[c.first]){
                distances[c.first] = distances[v]+c.second;
                pq.push({-distances[c.first], c.first});
            }
        }
    }
    if (distances[n - 1] == 99999999999){
        cout << -1;
        return 0;
    }
    cout << distances[n-1];
    return 0;
}
