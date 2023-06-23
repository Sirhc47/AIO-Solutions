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
    speed();
    int n;
    cin >> n;
    vector<int> choc(n);
    long long sum = 0;
    for (int i = 0; i < n; i++){
        cin >> choc[i];
        sum += choc[i];
    }
    long long mindiff = INT64_MAX;
    long long split = 0;
    for (int i = 0; i < n-1; i++){
        split += choc[i];
        if (abs(sum-2*split)<mindiff){
            mindiff = abs(sum - 2 * split);
        }
        //dbg(mindiff);
    }
    cout << mindiff;
}
