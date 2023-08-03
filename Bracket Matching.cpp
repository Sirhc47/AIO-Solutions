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
    speed();
    int n; cin >> n;
    stack<int> s;
    char x;
    for (int i = 0; i < n; i++){
        cin >> x;
        if (s.empty()){
            s.push(x);
            continue;
        }
        if (x == ']' && s.top() == '['){
            s.pop();
            continue;
        }
        if (x == ')' && s.top() == '('){
            s.pop();
            continue;
        }
        if (x == '}' && s.top() == '{'){
            s.pop();
            continue;
        }
        s.push(x);
    }
    if (s.empty()){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}
