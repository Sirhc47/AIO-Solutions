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
using namespace std;
int main() {
    file(where);
    int n, c;
    cin >> n >> c;
    int low = n+1;
    int high = -1;
    int x;
    for (int i = 0; i < c; i++){
        cin >> x;
        low = min(low, x);
        high = max(high, x);
    }
    low--;
    high--;
    vector<int> roads(n-1);
    for (int i = 0; i < n-1; i++){
        cin >> roads[i];
    }
    //find min time required for both banks, and find 
    int t = 1;
    int lowtime = 100000005;
    for (int i = low; i < high; i++){
        lowtime=min(lowtime, roads[i]-t);
        t++;
    }
    t = 1;
    int hightime = 100000005;
    for (int i = high-1; i >= low; i--){
        hightime=min(hightime, roads[i]-t);
        t++;
    }
    if (lowtime < 0 && hightime < 0){
        cout << 0;
        return 0;
    }
    vector<int> valid(n);
    if (lowtime >= 0){
        valid[low] = 1;
    }
    if (hightime >= 0){
        valid[high] = 1;
    }
    t = lowtime;
    for (int i = low-1; i >= 0; i--){
        t = min(t, roads[i]);
        t--;
        if (t >= 0){
            valid[i] = 1;
        }
        else{
            break;
        }
 
    }
    t = lowtime;
    for (int i = low; i < n-1; i++){
        t = min(t, roads[i]);
        t--;
        if (t >= 0){
            valid[i+1] = 1;
        }
        else{
            break;
        }
    }
    t = hightime;
    for (int i = high-1; i >= 0; i--){
        t = min(t, roads[i]);
        t--;
        if (t >= 0){
            valid[i] = 1;
        }
        else{
            break;
        }
    }
    t = hightime;
    for (int i = high; i < n-1; i++){
        t = min(t, roads[i]);
        t--;
        if (t >= 0){
            valid[i+1] = 1;
        }
        else{
            break;
        }
    }
 
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (valid[i] == 1){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
