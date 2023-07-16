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
    file(jewels);
    vector<int> bracelet;
    int n;
    cin >> n;
    char x;
    for (int i = 0; i < n; i++){
        cin >> x;
        if (x == 'r'){
            bracelet.push_back(1);
        }
        else{
            bracelet.push_back(2);
        }
    }
    vector<int> chains;
    int cur = bracelet[0];
    int first = bracelet[0];
    int length = 0;
    for (int i = 0; i < n; i++){
        if (bracelet[i] == cur){
            length++;
        }
        else{
            chains.push_back(length);
            length = 1;
            cur = bracelet[i];
        }
    }
    if (length == n){
        cout << n;
        return 0;
    }
    else if (cur == first){
        chains[0]+=length;
    }
    else{
        chains.push_back(length);
    }
    int ans = 0;
    for (int i = 0; i < chains.size()-1; i++){
        ans = max(ans, chains[i]+chains[i+1]);
    }
    ans = max(ans, chains[0]+chains[chains.size()-1]);
    cout << ans;

}
