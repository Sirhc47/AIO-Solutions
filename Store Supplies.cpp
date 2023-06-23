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
    int a, b, c;
    speed();
    vector<pair<int,int>> ranges;
    int x;
    int r;
    while (cin >> x){
        int count = 0;
        if (x == 0){
            break;
        }
        if (x == 1){
            cin >> a >> b;
            ranges.push_back(make_pair(a, b));
        }
        else{
            cin >> r;
            for (auto c : ranges){
                if (r >= c.first && r <= c.second){
                    count++;
                }
            }
            cout << count << endl;
        }
    }
}
