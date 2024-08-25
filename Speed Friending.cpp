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
    vector<ll> tree;
    vector<ll> arr;
    ll n;
 
    void build(ll node, ll start, ll end)
    {
        if (start == end)
        {
            // Leaf node will have a single element
            tree[node] = arr[start];
        }
        else
        {
            ll mid = (start + end) / 2;
            // Recursively build the segment tree
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            // Internal node will have the max of both of its children
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }
 
    void update(ll node, ll start, ll end, ll idx, ll val)
    {
        if (start == end)
        {
            // Leaf node
            arr[idx] = val;
            tree[node] = val;
        }
        else
        {
            ll mid = (start + end) / 2;
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
            // Internal node will have the max of both of its children
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }
 
    ll query(ll node, ll start, ll end, ll l, ll r)
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
        ll mid = (start + end) / 2;
        ll p1 = query(2 * node, start, mid, l, r);
        ll p2 = query(2 * node + 1, mid + 1, end, l, r);
        return max(p1, p2);
    }
 
public:
    SegmentTree(const vector<ll> &inputArr)
    {
        arr = inputArr;
        n = arr.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }
 
    void update(ll idx, ll val)
    {
        update(1, 0, n - 1, idx, val);
    }
 
    ll query(ll l, ll r)
    {
        return query(1, 0, n - 1, l, r);
    }
    vector<ll> getTree(){
        return tree;
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
 
class MinSegmentTree
{
private:
    vector<ll> tree;
    vector<ll> arr;
    ll n;
 
    void build(ll node, ll start, ll end)
    {
        if (start == end)
        {
            // Leaf node will have a single element
            tree[node] = arr[start];
        }
        else
        {
            ll mid = (start + end) / 2;
            // Recursively build the segment tree
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            // Internal node will have the max of both of its children
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }
 
    void update(ll node, ll start, ll end, ll idx, ll val)
    {
        if (start == end)
        {
            // Leaf node
            arr[idx] = val;
            tree[node] = val;
        }
        else
        {
            ll mid = (start + end) / 2;
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
            // Internal node will have the max of both of its children
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }
 
    ll query(ll node, ll start, ll end, ll l, ll r)
    {
        if (r < start || end < l)
        {
            // range represented by a node is completely outside the given range
            return 1000000000;
        }
        if (l <= start && end <= r)
        {
            // range represented by a node is completely inside the given range
            return tree[node];
        }
        // range represented by a node is partially inside and partially outside the given range
        ll mid = (start + end) / 2;
        ll p1 = query(2 * node, start, mid, l, r);
        ll p2 = query(2 * node + 1, mid + 1, end, l, r);
        return min(p1, p2);
    }
 
public:
    MinSegmentTree(const vector<ll> &inputArr)
    {
        arr = inputArr;
        n = arr.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }
 
    void update(ll idx, ll val)
    {
        update(1, 0, n - 1, idx, val);
    }
 
    int query(ll l, ll r)
    {
        return query(1, 0, n - 1, l, r);
    }
    vector<ll> getTree(){
        return tree;
    }
};
 
int main()
{
    int n; cin >> n;
    vector<ll> p(n);
    for (int i = 0; i < n; i++){
        cin >> p[i];
    }
    //keep a max segment tree
    SegmentTree st(p);
    //keep a min segment tree
    vector<ll> p2 = p;
    MinSegmentTree st2(p2);
    int q; cin >> q;
    while (q--){
        int t; cin >> t;
        if (t == 1){
            ll s; cin >> s;
            //last friend will always be the very left or very right
            s--;
            if (s == 0){
                cout << n << endl;
                continue;
            }
            if (s == n-1){
                cout << 1 << endl;
                continue;
            }
            ll lmax, lmin, rmax, rmin;
            lmax = st.query(0, s-1);
            lmin = st2.query(0, s-1);
            rmax = st.query(s+1, n-1);
            rmin = st2.query(s+1, n-1);
            ll labs = max(abs(p[s] - lmax), abs(p[s] - lmin));
            ll rabs = max(abs(p[s] - rmax), abs(p[s] - rmin));
            if (labs == rabs){
                cout << -1 << endl;
            }
            else if (labs > rabs){
                cout << 1 << endl;
            }
            else{
                cout << n << endl;
            }
        }
        else{
            ll s, x;
            cin >> s >> x;
            s--;
            st.update(s, x);
            st2.update(s, x);
            p[s] = x;
        }
    }
    return 0;
}
