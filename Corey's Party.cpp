#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <stack>
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
    file(party);
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<int> friendships(n+1);
    map<int, set<int>> f;
    vector<vector<int>> sus(n+1);
    int x, y;
    for (int i = 0; i < m; i++){
        cin >> x >> y;
        friendships[x]++;
        friendships[y]++;
        f[x].insert(y);
        f[y].insert(x);
        sus[x].push_back(y);
        sus[y].push_back(x);
    }
    bool change = true;
    vector<bool> alive(n+1, 1);
    int living = n;
    while (change == true){
        change = false;
        for (int i = 1; i <= n; i++)
        {
            //dbg(i);
            if (friendships[i] < a && alive[i])
            {
                change = true;
                for (auto c : f[i]){
                    friendships[c]--;
                }
                friendships[i] = 0;
                f[i].clear();
                alive[i] = false;
                living--;
                //cout << "killed\n";
            }
            else if (living - friendships[i]-1 < b && alive[i])
            {
                change = true;
                for (auto c : f[i]){
                    friendships[c]--;
                }
                friendships[i] = 0;
                f[i].clear();
                alive[i] = false;
                living--;
                //cout << "killed\n";
            }
        }
    }
    int ans = 0; 
    for (int i = 1; i<= n; i++){
        if (alive[i]){
            //cout << i << "\n";
            ans++;
        }
    }
    cout << ans;
}
