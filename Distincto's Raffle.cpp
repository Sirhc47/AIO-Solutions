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
    ifstream fin("rafflein.txt");
    ofstream fout("raffleout.txt");
    int n, k;
    fin >> n >> k;
    vector<int> nums(k+1);
    int a;
    for (int i = 0; i < n; i++){
        fin >> a;
        nums[a]++;
    }
    for (int i = 0; i <= k; i++){
        if (nums[i] == 1){
            fout << i;
            return 0;
        }
    }
    fout << -1;
    return 0;
}
