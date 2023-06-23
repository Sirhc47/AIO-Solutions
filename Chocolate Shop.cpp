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
    file(choc);
    int n;
    cin >> n;
    int sum = 0;
    int x;
    for (int i = 0; i < n; i++){
        cin >> x;
        sum += x;
    }
    if (sum%10 == 0){
        cout << 0 << "\n";
        return 0;
    }
    cout << 10-(sum%10);
}
