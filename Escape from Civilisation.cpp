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
vector<pair<int,int>> q;
int grid[1005][1005];
bool done[1005][1005];
int r, c;
int maxdepth = 0;
bool ok(int x, int y){
    return (x >= 0 && x < r && y >= 0 && y < c && grid[x][y] == 0 && done[x][y] == 0);
}
int bfs(vector<pair<int,int>> gri, int depth){
    vector<pair<int,int>> sus;
    if (gri.empty()){
        return depth-1;
    }
    maxdepth = max(depth, maxdepth);
    for (int i = 0; i < gri.size(); i++){
        int a = gri[i].first;
        int b = gri[i].second;
        //cout << a << " " << b << "\n";
        if (ok(a, b+1)){
            done[a][b+1] = 1;
            sus.push_back(make_pair(a, b+1));
        }
        if (ok(a, b - 1))
        {
            done[a][b - 1] = 1;
            sus.push_back(make_pair(a, b - 1));
        }
        if (ok(a+1, b))
        {
            done[a+1][b] = 1;
            sus.push_back(make_pair(a+1, b));
        }
        if (ok(a-1, b))
        {
            done[a-1][b] = 1;
            sus.push_back(make_pair(a-1, b));
        }
    }
    //cout << "\n\n";
    return bfs(sus, depth+1);
}
int main()
{
    speed();
    cin >> c >> r;
    //dbg(r);
    //dbg(c);
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> grid[i][j];
            if (grid[i][j] == 1){
                q.push_back(make_pair(i, j));
                done[i][j] = 1;
            }
        }
    }
    cout << bfs(q, 0);
    //use bfs starting with edges of civilisation
}
