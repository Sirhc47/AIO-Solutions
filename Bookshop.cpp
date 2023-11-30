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
#define ll long long
using namespace std;
int main() {
    speed();
    int n; cin >> n;
    vector<pair<int,int>> shelf(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        shelf[i] = {x, i};
    }
    int k; cin >> k;
    vector<int> published(k);
    for (int i = 0; i < k; i++){
        cin >> published[i];
    }
    //published is already sorted
    sort(shelf.begin(), shelf.end());
    int currentbook = 0;
    for (int i = 0; i < n; i++){
        if (shelf[i].first == published[currentbook]){
            cout << shelf[i].second+1 << "\n";
            currentbook++;
        }
        if (currentbook == k) break;
    }
    return 0;
}
