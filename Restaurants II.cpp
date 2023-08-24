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
    file(rest);
    int n, a, b;
    cin >> n >> a >> b;
    int x,y;
    vector<int>left;
    vector<int>right;
    long long ans = 0;
    for (int i = 0; i < n; i++){
        cin >> x >> y;
        if (x > y && x > 0){
            left.push_back(x-max(y,0));
            ans+=x;
        }
        else if (y>=x && y > 0){
            right.push_back(y-max(x,0));
            ans+=y;
        }

    }
    if (left.size() > a){
        //move the extra ones to the right that have the least difference
        sort(left.begin(), left.end());
        for (int i = 0; i < left.size()-a; i++){
            ans-=left[i];
        }

    }
    else if (right.size() > b){
        //move the extra ones to the left that have the least difference
        sort(right.begin(), right.end());
        for (int i = 0; i < right.size()-b; i++){
            ans-=right[i];
        }
    }
    cout << ans;

    return 0;
}
