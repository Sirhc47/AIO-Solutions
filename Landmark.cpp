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
int main()
{
    file(land);
    int r, c;
    cin >> r >> c;
    int grid[1001][1001];
    char x;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> x;
            if (x == '.')
            {
                grid[i][j] = 1;
            }
            if (x == '#')
            {
                grid[i][j] = 5;
            }
        }
    }
    int length = 0;
    int maxlength = 0;
    pair<int, int> start;
    pair<int, int> end;
    pair<int, int> maxstart;
    pair<int, int> maxend;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == 1)
            {
                length++;
                if (length == 1)
                {
                    start = make_pair(i + 1, j + 1);
                }
            }
            else
            {
                end = make_pair(i + 1, j);
                if (length > maxlength)
                {
                    maxstart = start;
                    maxend = end;
                    maxlength = length;
                }
                length = 0;
            }
        }
        end = make_pair(i + 1, c);
        if (length > maxlength)
        {
            maxstart = start;
            maxend = end;
            maxlength = length;
        }
        length = 0;
    }
    length = 0;
    for (int j = 0; j < c; j++)
    {
        for (int i = 0; i < r; i++)
        {
            if (grid[i][j] == 1)
            {
                length++;
                if (length == 1)
                {
                    start = make_pair(i + 1, j + 1);
                }
            }
            else
            {
                end = make_pair(i, j + 1);
                if (length > maxlength)
                {
                    maxstart = start;
                    maxend = end;
                    maxlength = length;
                }
                length = 0;
            }
        }
        end = make_pair(r, j + 1);
        if (length > maxlength)
        {
            maxstart = start;
            maxend = end;
            maxlength = length;
        }
        length = 0;
    }
    cout << maxstart.first << " " << maxstart.second << " " << maxend.first << " " << maxend.second;
}
