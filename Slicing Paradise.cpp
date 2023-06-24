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
    file(slice);
    int n; cin >> n;
    map<int, int> loc; //number to location
    int x;
    for (int i = 0; i < n; i++){
        cin >> x;
        loc[x] = i;
    }
    if (n == 1)
    {
        cout << 1;
        return 0;
    }

    int park = 1;
    vector<int> exist(n+2, 1);
    exist[0] = 0;
    exist[n+1] = 0;
    int maxpark = 0;
    int cut;
    for (int i = 1; i<=n; i++){
        cut = loc[i]+1;
        if (exist[cut+1]&&exist[cut-1]){
            park++;
            exist[cut] = 0;
        }
        else if (exist[cut+1] == 0 && exist[cut-1] == 0){
            park--;
            exist[cut] = 0;
        }
        else{
            exist[cut] = 0;
        }
        maxpark = max(park, maxpark);
    }
    cout << maxpark;
}
