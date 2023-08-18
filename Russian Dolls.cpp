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
    file(doll);
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> s;
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    for (int i = 0; i < n; i++){
        if (upper_bound(s.begin(),s.end(), v[i]) == s.end()){
            s.push_back(v[i]);
        }
        else{
            int index = upper_bound(s.begin(),s.end(), v[i]) - s.begin();
            s[index]=(v[i]);
        }
    }
    cout << s.size();
}
