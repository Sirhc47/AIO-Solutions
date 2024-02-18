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
using namespace std;
 
int main()
{
    speed();
    int n; cin >> n;
    //go from left and from right
    vector<int> v(n);
    vector<int> left(n), right(n);
    set<int> s;
    for (int i = 0; i < n; i++){
        cin >> v[i];
        s.insert(v[i]);
        left[i] = s.size();
    }
    s.clear();
    int ans = 0;
    for (int i = n-1; i >= 0; i--){
        s.insert(v[i]);
        right[i] = s.size();
    }
    for (int i = 0; i < n-1; i++){
        ans = max(ans, left[i] + right[i+1]);
    }
    cout << ans << "\n";
 
    return 0;
}
