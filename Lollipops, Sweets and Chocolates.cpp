#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
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
    file(lsc);
    int n, l;
    cin >> n >> l;
    vector<int> shops(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> shops[i];
    }
    vector<int> pamph(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> pamph[i];
    }
    int a = 1;
    int b = l;
    int shop;
    int prev;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    if (shops[pamph[1]] > shops[pamph[2]])
    {
        a = (shops[pamph[1]] + shops[pamph[2]]) / 2;
        b = l;
    }
    else
    {
        a = 1;
        b = (shops[pamph[1]] + shops[pamph[2]]) / 2;
    }
    prev = shops[pamph[2]];
    for (int i = 3; i <= n; i++)
    {
        //cout << a << " " << b << "\n";
        shop = shops[pamph[i]]; // 10 8 6 12 2 18
        if (shop < prev){
            a = max((shop+prev)/2, a);
        }
        else{
            b = min((shop+prev)/2, b);
        }
 
        if (a > b)
        {
            cout << -1;
            return 0;
        }
        prev = shop;
    }
    cout << a;
    return 0;
}
