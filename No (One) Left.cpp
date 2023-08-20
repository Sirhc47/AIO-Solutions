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
    file(left);
    int t; cin >> t;
    if (t == 1){
        cout << 0;
    }
    int x, y;
    vector<pair<int,int>> v(10005);
    vector<int> trolley(10005, 0);
    int start = 100005;
    int end = 0;
    for (int i = 0; i < t; i++){
        cin >> x >> y;
        start = min(start, x);
        end = max(end, x);
        if (!trolley[x]){
            v[x].first = y;
            v[x].second = y;
            trolley[x] = 1;
        }
        else{
            if (y > v[x].first)
            {
                v[x].first = y;
            }
            if (y < v[x].second)
            {
                v[x].second = y;
            }
        }
        
    }
    long long dist = 0;
    long long ans = 0;
    ans = end-start;
    int left = abs(v[start].first-v[start].second);
    int right = left;
    int lh = v[start].first;
    int rh = v[start].second;
    for (int i = start + 1; i <= end; i++){
        if (trolley[i]){
            int newl = min(left+abs(v[i].second-lh)+abs(v[i].first-v[i].second), right+abs(v[i].second-rh)+abs(v[i].first-v[i].second));
            int newr = min(left+abs(v[i].first-lh)+abs(v[i].first-v[i].second), right+abs(v[i].first-rh)+abs(v[i].first-v[i].second));
            left = newl;
            right = newr;
            lh = v[i].first;
            rh = v[i].second;
        }
    }
    ans += min(left, right);
    cout << ans;
    return 0;
}
