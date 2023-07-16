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
int dist[2005][2005];
int grid[2005][2005];
bool ok(int x, int y){
    return x >=0 && y >= 0;
}
void bfs(int a, int b){
    queue<pair<int, int>> q;
    q.push(make_pair(a, b));
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (ok(x+1, y) && grid[x+1][y] == 1 && dist[x][y]+1 < dist[x+1][y]){
            q.push(make_pair(x+1, y));
            dist[x+1][y] = dist[x][y]+1;
        }
        if (ok(x - 1, y) && grid[x - 1][y] == 1 && dist[x][y] + 1 < dist[x - 1][y])
        {
            q.push(make_pair(x - 1, y));
            dist[x - 1][y] = dist[x][y] + 1;
        }
        if (ok(x, y+1) && grid[x][y+1] == 1 && dist[x][y] + 1 < dist[x][y+1])
        {
            q.push(make_pair(x, y+1));
            dist[x][y+1] = dist[x][y] + 1;
        }
        if (ok(x, y-1) && grid[x][y-1] == 1 && dist[x][y] + 1 < dist[x][y-1])
        {
            q.push(make_pair(x, y-1));
            dist[x][y-1] = dist[x][y] + 1;
        }
    }
}


int main()
{
    for (int i = 0; i < 2005; i++)
    {
        for (int j = 0; j < 2005; j++)
        {
            dist[i][j] = 800000000;
        }
    }
    file(oil);
    int r, c, k;
    cin >>r >> c >> k;
    char x;
    int startx;
    int starty;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> x;
            if (x == '.'){
                grid[i][j] = 1;
            }
            if (x == '$'){
                grid[i][j] = 4;
                startx = i;
                starty = j;
                dist[i][j] = 0;
            }
        }
    }
    bfs(startx, starty);
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (i == startx && j == starty){
                cout << "$";
                continue;
            }
            if (dist[i][j] <= k && grid[i][j] == 1){
                cout << "*";
                continue;
            }
            if (grid[i][j] == 0){
                cout << "#";
                continue;
            }
            cout << ".";
            
        }
        cout << "\n";
    }

}
