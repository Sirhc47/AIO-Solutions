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
#define ll long long
using namespace std;
ll gcd(ll a, ll b)
{
    if (b > a)
    {
        return gcd(b, a);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
    // LCM = (a*b)/gcd(a,b)
}
int t[2000000];
void build(int a[], int v, int tl, int tr)
{
    if (tl == tr)
    {
        t[v] = a[tl];
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}
int sum(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return sum(v * 2, tl, tm, l, min(r, tm)) + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}
void update(int v, int tl, int tr, int pos, int new_val)
{
    if (tl == tr)
    {
        t[v] = new_val;
    }
    else
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}
const int dx[5]{1, 0, -1, 0, 0}, dy[5]{0, 1, 0, -1, 0};

int main()
{
    speed();
    int r, c, n;
    cin >> r >> c >> n;
    string s;
    cin >> s;
    map<pair<int,int>, int> grid;
    int x = 0, y = 0;
    grid[{0,0}] = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'N')
        {
            y -= 1;
        }
        else if (s[i] == 'S')
        {
            y += 1;
        }
        else if (s[i] == 'E')
        {
            x += 1;
        }
        else if (s[i] == 'W')
        {
            x -= 1;
        }
        grid[{y,x}] = 1;
    }
    // bfs from 0, 0 to find the shortest path to x,y
    // but make the path in reverse direction
    queue<pair<pair<int, int>, string>> q;
    q.push({{0, 0}, ""});
    grid[{0,0}] = 2;
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        if (p.first.first == x && p.first.second == y)
        {
            cout << p.second.size() << endl;
            cout << p.second << endl;
            return 0;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = p.first.first + dx[i];
            int ny = p.first.second + dy[i];
            if (nx >= 0 && nx < c && ny >= 0 && ny < r && grid[{ny,nx}] == 1)
            {
                grid[{ny,nx}] = 2;
                if (i == 0)
                {
                    q.push({{nx, ny}, "W" + p.second});
                }
                else if (i == 1)
                {
                    q.push({{nx, ny}, "N" + p.second});
                }
                else if (i == 2)
                {
                    q.push({{nx, ny}, "E" + p.second});
                }
                else if (i == 3)
                {
                    q.push({{nx, ny}, "S" + p.second});
                }
            }
        }
    }

    return 0;
}
