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
int n;
vector<vector<int>> tree;

vector<int> done;
vector<int> val;
vector<int> top;
map<int, pair<int,int>> root;



int solve(int node){
    int ans = 0;
    if (top[tree[node][0]]){
        val[tree[node][0]] = tree[node][1];
        done[tree[node][0]] = 1;
    }
    if (top[tree[node][2]]){
        val[tree[node][2]] = tree[node][3];
        done[tree[node][2]] = 1;
    }


    if (done[tree[node][0]] && done[tree[node][2]]){
        ans += abs(val[tree[node][0]] - val[tree[node][2]]);
        val[node] = max(val[tree[node][0]], val[tree[node][2]]) + root[node].first; // plus previous stick
        done[node] = 1;
        return ans;
    }
    if (done[tree[node][0]]){
        ans += solve(tree[node][2]);
        ans += abs(val[tree[node][0]] - val[tree[node][2]]);
        val[node] = max(val[tree[node][0]], val[tree[node][2]]) + root[node].first;
        done[node] = 1;
        return ans;
    }
    if (done[tree[node][2]]){
        ans += solve(tree[node][0]);
        ans += abs(val[tree[node][0]] - val[tree[node][2]]);
        val[node] = max(val[tree[node][0]], val[tree[node][2]]) + root[node].first;
        done[node] = 1;
        return ans;
    }
    ans += solve(tree[node][0]);
    ans += solve(tree[node][2]);
    ans += abs(val[tree[node][0]] - val[tree[node][2]]);
    val[node] = max(val[tree[node][0]], val[tree[node][2]]) + root[node].first;
    done[node] = 1;
    return ans;
}



int main()
{
    file(sculp);
    cin >> n;
    done.resize(n, 0);
    val.resize(n, 0);
    if (n == 1){
        cout << 0;
        return 0;
    }
    tree.resize(n);
    top.resize(n, 0);
    root[0] = {0, 0};
    for (int i = 0; i < n; i++){
        int a, x, b, y;
        cin >> a >> x >> b >> y;
        tree[i].push_back(a-1);
        tree[i].push_back(x);
        tree[i].push_back(b-1);
        tree[i].push_back(y);
        root[a-1] = {x, i};
        root[b-1] = {y, i};
        if (x == 0 && y == 0){
            done[i] = 1;
            top[i] = 1;
        }
    }


    cout << solve(0);



}
