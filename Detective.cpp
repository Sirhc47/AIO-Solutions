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
    file(detective);
    int n, m;
    cin >> n >> m;
    int a, b, d;
    vector<vector<pair<int, int>>> f(n + 1);
    vector<vector<int>> accuse(n + 1);
    vector<vector<int>> raccuse(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> d;
        if (d == 3)
        {
            accuse[a].push_back(b);
            raccuse[b].push_back(a);
        }
        else
        {
            f[a].push_back(make_pair(b, d));
            f[b].push_back(make_pair(a, d));
        }
    }
    vector<int> visited(n + 1, 0);
    vector<int> value(n + 1, 0);
    set<int> truth;
    set<int> lies;
    vector<int> possible(n + 1, 1);
    vector<int> added(n + 1, 0);
    vector<pair<int, int>> accused(n+1);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            queue<pair<int, int>> q;
            q.push(make_pair(i, 0));
            added[i] = 1;
            while (!q.empty())
            {
                int node = q.front().first;
                value[node] = q.front().second;
                q.pop();
                visited[node] = 1;
                if (value[node] % 2 == 0)
                {
                    for (auto c : accuse[node])
                    {
                        truth.insert(c);
                    }
                }
                else
                {
                    for (auto c : accuse[node])
                    {
                        lies.insert(c);
                    }
                }
                for (auto c : accuse[node])
                {
                    if (accused[c].first){
                        if (accused[c].second%2 != (value[node])%2){
                            cout << "MISTAKE";
                            return 0;
                        }
                        continue;
                    }
                    accused[c] = make_pair(1, value[node]);
                    for (auto d : raccuse[c])
                    {
                        if (!visited[d])
                        {
                            if (!added[d])
                            {
                                added[d] = 1;
                                q.push(make_pair(d, value[node]));
                            }
                        }
                        else
                        {
                            if (value[d] % 2 != (value[node]) % 2)
                            {
                                cout << "MISTAKE";
                                return 0;
                            }
                        }
                    }
                }
                for (auto c : f[node])
                {
                    if (!visited[c.first])
                    {
                        if (!added[c.first])
                        {
                            added[c.first] = 1;
                            q.push(make_pair(c.first, value[node] + c.second - 1));
                        }
                    }
                    else
                    {
                        if (value[c.first] % 2 != (value[node] + c.second - 1) % 2)
                        {
                            cout << "MISTAKE";
                            return 0;
                        }
                    }
                }
            }
 
            if (truth.size() > 1 && lies.size() > 1)
            {
                cout << "MISTAKE";
                return 0;
            }
            if (truth.size() > 1)
            {
                if (lies.size() == 1)
                {
                    // remove everything but the one
                    for (int i = 0; i < possible.size(); i++)
                    {
                        if (i != *lies.begin())
                        {
                            possible[i] = 0;
                        }
                    }
                }
                else
                {
                    // remove every truth
                    for (auto c : truth)
                    {
                        possible[c] = 0;
                    }
                }
            }
            if (lies.size() > 1)
            {
                if (truth.size() == 1)
                {
                    // remove everything but the one
                    for (int i = 0; i < possible.size(); i++)
                    {
                        if (i != *truth.begin())
                        {
                            possible[i] = 0;
                        }
                    }
                }
                else
                {
                    // remove every lie
                    for (auto c : lies)
                    {
                        possible[c] = 0;
                    }
                }
            }
            if (lies.size() == 1 && truth.size() == 1)
            {
                // remove everything  but those two
                for (int i = 0; i < possible.size(); i++)
                {
                    if (i != *lies.begin() && i != *truth.begin())
                    {
                        possible[i] = 0;
                    }
                }
            }
 
            truth.clear();
            lies.clear();
        }
    }
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (possible[i])
        {
            cout << i << "\n";
            count++;
        }
    }
    if (count == 0)
    {
        cout << "MISTAKE";
    }
    return 0;
}
