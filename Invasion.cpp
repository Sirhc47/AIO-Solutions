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
int r, c;
bool isValid(int x, int y){
    if (x < 0 || x >= r || y < 0 || y >= c){
        return false;
    }
    return true;
}
int main()
{
    file(inv);
    char grid[1005][1005];
    cin >> r >> c;
    map<char, set<char>> neighbours;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (isValid(i+1, j)){
                if (grid[i+1][j] != grid[i][j]){
                    neighbours[grid[i][j]].insert(grid[i + 1][j]);
                }
            }
            if (isValid(i - 1, j))
            {
                if (grid[i - 1][j] != grid[i][j])
                {
                    neighbours[grid[i][j]].insert(grid[i - 1][j]);
                }
            }
            if (isValid(i, j+1))
            {
                if (grid[i][j+1] != grid[i][j])
                {
                    neighbours[grid[i][j]].insert(grid[i][j+1]);
                }
            }
            if (isValid(i, j-1))
            {
                if (grid[i][j-1] != grid[i][j])
                {
                    neighbours[grid[i][j]].insert(grid[i][j-1]);
                }
            }
        }
    }
    int ans = 0;
    for (auto c : neighbours){
        if (c.second.size() > ans){
            ans = c.second.size();
        }
    }
    cout << ans;
}
