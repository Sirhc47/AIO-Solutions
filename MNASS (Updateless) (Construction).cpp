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
 
 
 
typedef pair<int,int> pii;
 
 
 
 
 
int main(){
 
    int n; cin >> n;
 
    vector<ll> v(n);
 
    for (int i= 0; i < n; i++){
 
        cin >> v[i];
 
    }
 
    vector<ll> dp(n);
    vector<int> used(n, 0); //is this used
    dp[0] = max(v[0],0ll);
    if (v[0] > 0){
        used[0] = 1;
    }
 
    if (n == 1){
        if (used[0]){
            cout << 1 << "\n" << 1;
        }
        else{
            cout << 0;
        }
        return 0;
 
    }
 
    dp[1] = max(dp[0],v[1]);
    if (v[1] > dp[0]){
        used[1] = 1;
    }
 
    for (int i = 2; i < n; i++){
        if (dp[i-2] + v[i] > dp[i-1]){
            used[i] = 1;
        }
        dp[i] = max(dp[i-1],dp[i-2]+v[i]);
 
    }
 
    stack<int> s;
    int x= n-1;
    while (x>=0){
        if (used[x]){
            s.push(x);
            x-=2;
        }
        else{
            x--;
        }
    }
    cout << s.size() << "\n";
    while (!s.empty()){
        x = s.top();
        s.pop();
        x++;
        cout << x << " ";
    }
    return 0;
 
}
