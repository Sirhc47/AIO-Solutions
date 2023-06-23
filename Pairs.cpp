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
    file(pair);
    int n;
    cin >> n;
    map<int, int> location;
    int a;
    int dist;
    int maxdist = 0;
    for (int i = 0; i < 2*n; i++){
        cin >> a;
        if (location[a] == 0){
            location[a] = i+1;
        }
        else{
            dist = abs(i+1-location[a]);
            if (dist > maxdist){
                maxdist = dist;
            }
        }
    }
    cout << maxdist;
}
