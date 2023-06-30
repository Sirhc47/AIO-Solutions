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
bool visited[1001][1001];
int w, h;
int cave[1001][1001];
bool ok(int x, int y)
{
    return (x >= 0 && y >= 0 && x < h && y < w);
}
int sum = 1;
int splits(int x, int y)
{
    int temp = 0;
    vector<pair<int, int>> neighbours;
    //cout << x << " " << y << "\n";
    if (visited[x][y])
    {
        return 0;
    }
    visited[x][y] = true;
    if (ok(x + 1, y) && cave[x + 1][y] == 1 && !visited[x + 1][y])
    {
        neighbours.push_back(make_pair(x + 1, y));
        temp++;
    }
    if (ok(x - 1, y) && cave[x - 1][y] == 1 && !visited[x - 1][y])
    {
        neighbours.push_back(make_pair(x - 1, y));
        temp++;
    }
    if (ok(x, y + 1) && cave[x][y + 1] == 1 && !visited[x][y + 1])
    {
        neighbours.push_back(make_pair(x, y + 1));
        temp++;
    }
    if (ok(x, y - 1) && cave[x][y - 1] == 1 && !visited[x][y - 1])
    {
        neighbours.push_back(make_pair(x, y - 1));
        temp++;
    }
    sum += max(temp-1, 0);
    for (auto c : neighbours)
    {
        splits(c.first, c.second);
    }
    return 0;
}
int main()
{
    file(cave);
    char x;
    cin >> h >> w;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> x;
            if (x == '.')
            {
                cave[i][j] = 1;
            }
            if (x == '#')
            {
                cave[i][j] = 5;
            }
        }
    }
    splits(0, 0);
    cout << sum;
}
