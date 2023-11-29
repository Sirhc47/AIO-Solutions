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
    file(nom);
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<long long> partialSums(n);
    long long sum = 0;
    for (int i = 0; i < n; i++){
        sum += v[i];
        partialSums[i] = sum;
    }
    for (int i = n-1; i >= 0; i--){
        //if half of the partial sum exists in the vector, return it
        if (partialSums[i]%2 == 1){
            continue;
        }
        vector<long long>::iterator it = lower_bound(partialSums.begin(), partialSums.end(), partialSums[i]/2);
        if (partialSums[it-partialSums.begin()] == partialSums[i]/2){
            cout << partialSums[i]/2;
            return 0;
        }
    }
    cout << 0;
    return 0;
}
