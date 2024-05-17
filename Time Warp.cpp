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
    speed();
    int x, w; cin >> x >> w;
    vector<ll> a(x);
    vector<ll> pfx;
    ll sum = 0;
    pfx.push_back(0);
    for (int i = 0; i < x; i++) {
        cin >> a[i];
        sum += a[i];        
        pfx.push_back(sum);
    }
    ll ans = pfx[x];
    vector<int> jumps;
    for (int i = 0; i < w; i++) {
        int y; cin >> y;
        jumps.push_back(y);
    }
    for (int i = 0; i < w; i++){
        //add the max jump value to answer
        //in other words, add the value of the largest sum of subarray with length of jump[i]
        ll dist = jumps[i];
        ll max_sum = 0;
        for (int j = dist; j<= x; j++){
            max_sum = max(max_sum, pfx[j] - pfx[j-dist]);
        }
        ans += max_sum;
    }
    cout << ans << endl;

    return 0;
}
