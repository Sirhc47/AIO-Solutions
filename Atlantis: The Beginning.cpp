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
vector<vector<int>> grid;
vector<vector<int>> path;
int r, c;
void sirhc(int x, int y){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    while (!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        int prev = grid[a][b];
        int length = path[a][b];
        if (b-1 >= 0 && grid[a][b-1] < prev && path[a][b-1] < length+1){
            path[a][b-1] = max(path[a][b-1], length+1);
            q.push(make_pair(a, b-1));
        }
        if (b+1 < c && grid[a][b+1] < prev && path[a][b+1] < length+1){
            path[a][b+1] = max(path[a][b+1], length+1);
            q.push(make_pair(a, b+1));
        }
        if (a-1 >= 0 && grid[a-1][b] < prev && path[a-1][b] < length+1){
            path[a-1][b] = max(path[a-1][b], length+1);
            q.push(make_pair(a-1, b));
        }
        if (a+1 < r && grid[a+1][b] < prev && path[a+1][b] < length+1){
            path[a+1][b] = max(path[a+1][b], length+1);
            q.push(make_pair(a+1, b));
        }
    }
}
int main()
{
    file(atlan);
    int x,y; 
    cin >> r >> c;
    cin >> x >> y;
    int sus;
    vector<int> temp;
    vector<int> amogus;
    for (int i = 0; i < r; i++){
        temp.clear();
        amogus.clear();
        for (int j = 0; j < c; j++){
            cin >> sus;
            temp.push_back(sus);
            amogus.push_back(0);
        }
        grid.push_back(temp);
        path.push_back(amogus);
    }
    path[x-1][y-1] = 1;
    sirhc(x-1, y-1);
    int ans = 0;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            //cout << path[i][j] << " ";
            ans = max(path[i][j], ans);
        }
        //cout << "\n";
    }
    //cout << "\n";
    cout << ans;
 
}
