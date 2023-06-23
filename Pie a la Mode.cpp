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
using namespace std;
int main()
{
    file(mode);
    int p; cin >> p;
    map<int, int> count;
    int x;
    for (int i = 0; i < p; i++){
        cin >> x;
        count[x]++;
    }
    int ice, times;
    times = 0;
    for (auto c : count){
        if (c.second > times){
            times = c.second;
            ice = c.first;
        }
    }
    cout << ice << " " << times;
}
