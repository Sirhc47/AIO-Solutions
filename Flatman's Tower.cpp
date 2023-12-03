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
#define ll long long
using namespace std;
int main() {
    speed();
    int n, h;
    cin >> n >> h;
    vector<pair<int, int>> boxes(n);
    for (int i = 0; i < n; i++) {
        cin >> boxes[i].first >> boxes[i].second;
    }
    //bases don't matter because you can rearrange to have largest to smallest base
    //so we are just looking for the largest height that you can make with boxes which is less than h
    vector<int> dp(h+1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++){
        vector<int> temp;
        for (int j = h; j >= 0; j--){
            if (j-boxes[i].first >= 0 && dp[j-boxes[i].first] == 1){
                temp.push_back(j);
            }
            if (j-boxes[i].second >= 0 && dp[j-boxes[i].second] == 1){
                temp.push_back(j);
            }
        }
        for (int k = 0; k < temp.size(); k++){
            dp[temp[k]] = 1;
        }
    }
    for (int i = h; i >= 0; i--){
        if (dp[i] == 1){
            cout << i << "\n";
            return 0;
        }
    }



    return 0;
}
