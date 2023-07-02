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
    file(ticket);
    int a, ac;
    int b, bc;
    cin >> ac >> a >> bc >> b;
    int n;
    cin >> n;
    vector<int> days(n);
    for (int i = 0; i<n; i++){
        cin >> days[i];
    }
    int INF = 1e9;
    vector<int> dp(n+1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i-1; j >= 0; j--){
            int v = days[i-1]-days[j]+1;
            if (v <= a){
                dp[i] = min(dp[i], dp[j] + ac);
            }
            if (v <= b){
                dp[i] = min(dp[i], dp[j]+bc);
            }
        }
    }
    cout << dp[n];
    return 0;
}
