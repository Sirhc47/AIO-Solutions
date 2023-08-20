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
    file(art);
    int h, w;
    cin >> h >> w;
    char a[1005][1005];
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    bool done[1005][1005];
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (a[i][j] == 'X' && done[i][j] == false)
            {
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                done[i][j] = true;
                vector<pair<int, int>> coords;
                map<int,vector<int>> vert;
                map<int,vector<int>> hor;
                while (!q.empty())
                {
                    pair<int, int> p = q.front();
                    q.pop();
                    int x = p.first;
                    int y = p.second;
                    if (!(x > 0 && a[x - 1][y] == 'X' && x < h - 1 && a[x + 1][y] == 'X') && !(y > 0 && a[x][y - 1] == 'X' && y < w - 1 && a[x][y + 1] == 'X'))
                    {
                        vert[y].push_back(x);
                        hor[x].push_back(y);
                    }
                    if (x > 0 && a[x - 1][y] == 'X' && done[x - 1][y] == 0)
                    {
                        q.push(make_pair(x - 1, y));
                        done[x - 1][y] = 1;
                    }
                    if (x < h - 1 && a[x + 1][y] == 'X' && done[x + 1][y] == 0)
                    {
                        q.push(make_pair(x + 1, y));
                        done[x + 1][y] = 1;
                    }
                    if (y > 0 && a[x][y - 1] == 'X' && done[x][y - 1] == 0)
                    {
                        q.push(make_pair(x, y - 1));
                        done[x][y - 1] = 1;
                    }
                    if (y < w - 1 && a[x][y + 1] == 'X' && done[x][y + 1] == 0)
                    {
                        q.push(make_pair(x, y + 1));
                        done[x][y + 1] = 1;
                    }
                }


                for (auto c : vert){
                    vector<int> v = c.second;
                    sort(v.begin(),v.end());
                    coords.push_back(make_pair(v[0],c.first));
                    coords.push_back(make_pair(v[v.size()-1],c.first));
                }
                for (auto c : hor){
                    vector<int> v = c.second;
                    sort(v.begin(),v.end());
                    coords.push_back(make_pair(c.first,v[0]));
                    coords.push_back(make_pair(c.first,v[v.size()-1]));
                }

                int mx = 0;
                // find max distance
                for (int i = 0; i < coords.size(); i++)
                {
                    for (int j = i + 1; j < coords.size(); j++)
                    {
                        int x1 = coords[i].first;
                        int y1 = coords[i].second;
                        int x2 = coords[j].first;
                        int y2 = coords[j].second;
                        int dist = abs(x1 - x2) + abs(y1 - y2);
                        if (dist > mx)
                        {
                            mx = dist;
                        }
                    }
                }
                if (mx > ans)
                {
                    ans = mx;
                }
            }
        }
    }
    cout << ans;

    return 0;
}
