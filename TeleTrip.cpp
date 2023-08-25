#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <climits>
#include <string>
#define speed() \
    ios::sync_with_stdio(false); \
    cin.tie(0)
#define file(name) \
    speed(); \
    freopen(#name "in.txt", "r", stdin); \
    freopen(#name "out.txt", "w", stdout)
#define dbg(x) cout << '>' << #x << ':' << x << endl;
using namespace std;
int main() {
    ifstream input("telein.txt");
    ofstream output("teleout.txt");
    int n;
    char x;
    input >> n;
    int loc = 0;
    set<int> visited;
    visited.insert(0);
    for (int i = 0; i < n; i++){
        input >> x;
        if (x == 'L'){
            loc--;
        }
        else if (x== 'R'){
            loc++;
        }
        else if (x == 'T'){
            loc = 0;
        }
        visited.insert(loc);

    }
    output << visited.size();
    return 0;
}
