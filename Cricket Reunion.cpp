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
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//Sirhc47
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
 
int main()
{
    int n, m, t;
    cin >> n >> m >> t;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    priority_queue<pair<int, int>> pq; //distance can travel, node
    for (int i = 0; i < t; i++){
        int l,k;
        cin >> l >> k;
        l--;
        pq.push({k,l});
    }
    vector<int> viable(n, 0);
    vector<int> dist(n, -1);
    while (!pq.empty()){
        int k = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (k < dist[u]){
            continue;
        }
        viable[u] = 1;
        dist[u] = k;
        if (k == 0){
            continue;
        }
        for (int v : adj[u]){
            if (dist[u] -1 > dist[v]){
                pq.push({dist[u]-1, v});
                dist[v] = dist[u] - 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans += viable[i];
    }
    cout << ans;
    return 0;
}
