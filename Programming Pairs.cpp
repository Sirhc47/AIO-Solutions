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
    file(pairs);
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    long long ans = 0;


    int high;
    int low;
    for (int i = 0; i < n; i++){
        high = b-v[i];
        low = a-v[i];
        auto lb = lower_bound(v.begin(), v.end(), low);
        auto ub = upper_bound(v.begin(), v.end(), high);
        ans+=(ub-lb);
        if (low <= v[i] && v[i] <= high){
            ans--;
        }
    }
    cout << ans/2;
}
