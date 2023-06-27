#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
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
    file(shuffle);
    int n, k;
    cin >> n >> k;
    vector<int> c;
    vector<int> p;
    map<int, int> minister;
    int x;
    for (int i = 0; i < k; i++)
    {
        cin >> x;
        c.push_back(x);
    }
    int special = c[0];
    for (int i = 0; i < k + 1; i++)
    {
        cin >> x;
        p.push_back(x);
        minister[x] = i + 1;
    }
    int pm = 0;
    vector<int> round2;
    for (int i = k; i >= 0; i--){
/*         dbg(p[i]);
        dbg(*lower_bound(c.begin(), c.end(), p[i])); */
        if (lower_bound(c.begin(), c.end(), p[i]) != c.end()){
            if (*lower_bound(c.begin(), c.end(), p[i]) == special){
                pm = i+1;
            }
            c.erase(lower_bound(c.begin(), c.end(), p[i]));
        }
        else{
            round2.push_back(p[i]);
        }
    }
    int kick = minister[round2.back()];
    if (pm == 0){
        pm = minister[round2[0]];
    }
    cout << pm << "\n" << kick;

}
