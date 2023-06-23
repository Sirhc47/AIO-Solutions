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
    file(debts);
    int min = 1;
    int sum = 0;
    int n;
    cin >> n;
    int x;
    vector<int> vals;
    for (int i = 0; i < n; i++){
        cin >> x;
        vals.push_back(x);
        sum -= x;
        if (sum < min){
            min = sum;
        }
    }
    if (min == 0){
        cout << 1 << "\n";
        return 0;
    }
    int extra = 0;
    for (int i = n-1; i > 0; i--){
        extra -= vals[i];
        if (extra >= -1*min){
            cout << i+1 << "\n";
            return 0;
        }
    }
}
