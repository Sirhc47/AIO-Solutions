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
    file(arth);
    int n, p;
    cin >> n >> p;
    if (p == 0){
        cout << n;
        return 0;
    }
    vector<vector<int>> amogus(n+1);
    vector<int> duel(n+1);
    vector<int> done(n+1,0);
    for (int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        amogus[x].push_back(y);
        amogus[y].push_back(x);
        duel[x] = 1;
        duel[y] = 1;
    }
    int ans = n;
    for (int i = 1; i <=n; i++){
        if (duel[i] && !done[i]){
            queue<pair<int,int>> sus;
            int left = 0;
            int right = 0;
            sus.push({i, 0});
            done[i] = 1;
            while (!sus.empty()){
                int knight = sus.front().first;
                int imp = sus.front().second;
                sus.pop();
                if (imp%2 == 0){
                    left++;
                }
                else{
                    right++;
                }
                for (auto c : amogus[knight]){
                    if (!done[c]){
                        sus.push({c,  imp+1});
                        done[c] = 1;
                    }
                }
            }
            ans-= min(left, right);
        }
    }
    cout << ans;
 
 
}
