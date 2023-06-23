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
vector<int> hay;
int main()
{
    file(bernard);
    int n; cin >> n;
    map<int, int> sus;
    int x;
    for (int i = 1; i <= n; i++){
        cin >> x;
        sus[x] = i;
    }
    while (cin >> x){
        if (x == -1){
            break;
        }
        if (sus.count(x)){
            cout << sus[x] << "\n";
        }
        else{
            cout << "needle is gone forever\n";
        }
    }
 
}
