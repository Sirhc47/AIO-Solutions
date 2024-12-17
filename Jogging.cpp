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
#include <unordered_map>
#define speed()                  \
    ios::sync_with_stdio(false); \
    cin.tie(0)
#define file(name)                       \
    speed();                             \
    freopen(#name "in.txt", "r", stdin); \
    freopen(#name "out.txt", "w", stdout)
#define dbg(x) cout << '>' << #x << ':' << x << endl;
#define ll long long
//Sirhc47
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
class SegmentTree
{
private:
    vector<int> tree;
    vector<int> arr;
    int n;
 
    void build(int node, int start, int end)
    {
        if (start == end)
        {
            // Leaf node will have a single element
            tree[node] = arr[start];
        }
        else
        {
            int mid = (start + end) / 2;
            // Recursively build the segment tree
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            // Internal node will have the sum of both of its children
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
 
    void update(int node, int start, int end, int idx, int val)
    {
        if (start == end)
        {
            // Leaf node
            arr[idx] = val;
            tree[node] = val;
        }
        else
        {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid)
            {
                // If idx is in the left child, recurse on the left child
                update(2 * node, start, mid, idx, val);
            }
            else
            {
                // If idx is in the right child, recurse on the right child
                update(2 * node + 1, mid + 1, end, idx, val);
            }
            // Internal node will have the sum of both of its children
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
 
    int query(int node, int start, int end, int l, int r)
    {
        if (r < start || end < l)
        {
            // range represented by a node is completely outside the given range
            return 0;
        }
        if (l <= start && end <= r)
        {
            // range represented by a node is completely inside the given range
            return tree[node];
        }
        // range represented by a node is partially inside and partially outside the given range
        int mid = (start + end) / 2;
        int p1 = query(2 * node, start, mid, l, r);
        int p2 = query(2 * node + 1, mid + 1, end, l, r);
        return p1 + p2;
    }
 
public:
    SegmentTree(const vector<int> &inputArr)
    {
        arr = inputArr;
        n = arr.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }
 
    void update(int idx, int val)
    {
        update(1, 0, n - 1, idx, val);
    }
 
    int query(int l, int r)
    {
        return query(1, 0, n - 1, l, r);
    }
};
long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int countDigits(ll n)
{
    int digits = 0;
    while (n > 0)
    {
        n /= 10;
        digits++;
    }
    return digits;
}
vector<int> z_function(string s)
{
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i < r)
        {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        {
            z[i]++;
        }
        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
void printv(const vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
const int dx[5] {1, 0, -1, 0, 0}, dy[5]{0, 1, 0, -1, 0};
#define pii pair<int,int>
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> adj1(n);
    vector<vector<pii>> adj2(n);
    for (int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj1[a].push_back({b,c});
        adj2[b].push_back({a,c});
    }
    vector<ll> dist1(n, 9999999999);
    vector<ll> dist2(n, 9999999999);
    vector<int> seen1(n);
    vector<int> seen2(n);
    priority_queue<pii, vector<pii>, greater<pii>> pq1;
    priority_queue<pii, vector<pii>, greater<pii>> pq2;
    dist1[0] = 0;
    pq1.push({0, 0});
    while (!pq1.empty()){
        int cost = pq1.top().first;
        int u = pq1.top().second;
        pq1.pop();
        if (seen1[u]){
            continue;
        }
        seen1[u] = 1;
        for (auto edge : adj1[u]){
            if (cost + edge.second < dist1[edge.first]){
                dist1[edge.first] = cost + edge.second;
                pq1.push({dist1[edge.first], edge.first});
            }
        }
    }
    dist2[0] = 0;
    pq2.push({0,0});
    while (!pq2.empty()){
        int cost = pq2.top().first;
        int u = pq2.top().second;
        pq2.pop();
        if (seen2[u]){
            continue;
        }
        seen2[u] = 1;
        for (auto edge : adj2[u]){
            if (cost + edge.second < dist2[edge.first]){
                dist2[edge.first] = cost + edge.second;
                pq2.push({dist2[edge.first], edge.first});
            }
        }
    }
    for (int i = 1; i < n; i++){
        if (seen1[i] && seen2[i]){
            cout << dist1[i] + dist2[i] << "\n";
        }
        else{
            cout << -1 << "\n";
        }
    }
    return 0;
}
