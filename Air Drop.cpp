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
    file(drop);
    int n; cin >> n;
    vector<int> v(n);
    vector<map<int,int>> left(n);
    if (n == 1){
        cout << 1;
        return 0;
    }
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
 
    for (int i = 1; i < n; i++){
        left[0][v[i]-v[0]] = 1;
    }
    int ans = 1;
    for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++){
            left[i][v[i]-v[j]] = max(left[j][v[i]-v[j]] + 1,2);
            ans = max(ans, left[i][v[i]-v[j]]);
        }
    }
    cout << ans;
 
 
 
}
