#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
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
    speed();
    int n; cin >> n;
    vector<int> segs(n);
    vector<int> reds;
    vector<int> blues;
    for (int i = 0; i < n; i++){
        cin >> segs[i];
        if (segs[i] == 1){
            reds.push_back(i);
        }
        else{
            blues.push_back(i);
        }
    }
    long long bways = 0;
    long long rways = 0;
    vector<long long> dp(n);
    if (segs[0] == 1){
        dp[0] = 1;
        bways = 1;
    }
    else{
        dp[0] = 1;
        rways = 1;
    }
    for (int i = 1; i < n; i++){
/*         dbg(i);
        dbg(bways);
        dbg(rways); */
        if (segs[i] == 1){
            dp[i] = rways % 1000000007;
            bways += rways % 1000000007;
        }
        else{
            dp[i] = bways % 1000000007;
            rways += bways % 1000000007;
        }
    }
    cout << dp[n-1];
}
