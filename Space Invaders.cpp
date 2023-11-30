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

int main()
{
    file(space);
    int w, h; cin >> w >> h;
    int k; cin >> k;
    vector<pair<int, int>> v;
    while (k--){
        int p; cin >> p;
        int maxx = -1;
        int minx = w+5;
        for (int i = 0; i < p; i++){
            int x, y; cin >> x >> y;
            minx = min(minx, x);
            maxx = max(maxx, x);
        }
        if (minx == maxx){
            continue;
        }
        v.push_back({minx, maxx-1});

    }
    sort(v.begin(), v.end());
    //merge connected intervals
    vector<pair<int, int>> newv;

    for (int i = 0; i < v.size(); i++){
        pair<int, int> curr = v[i];
        while (i < v.size()-1 && curr.second+1 >= v[i+1].first){
            curr.second = max(curr.second, v[i+1].second);
            i++;
        }
        newv.push_back(curr);
    }
    int ans = w;
    for (auto c : newv){
        ans -= (c.second-c.first+1);
    }
    cout << ans;


    return 0;
}


