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
bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second)
    {
        return a.second < b.second;
    }
    return a.first > b.first;
}
int main()
{
    file(ruckus);
    int n, l, k, m;
    cin >> n >> l >> k >> m;
    vector<int> hands(n + 1);
    map<int,int> back;
    int a, b;
    for (int i = 0; i < l; i++)
    {
        cin >> a >> b;
        hands[a] = b;
        back[b] = a;
    }
    vector<pair<int, int>> gc;
    int s = 0;
    int close;
    vector<bool> done(n + 1, false);
    for (int i = 1; i <= n; i++){
        if (done[i]){
            continue;
        }
        s = 1;
        int start;
        int d = i;
        close = 0;
        while (back.count(d) && back[d] != i){
            d = back[d];
        }
        start = d;
        //dbg(start);
        while(hands[d]){
            done[d] = true;
            if (hands[d] == start){
                close = 1;
                break;
            }
            d = hands[d];
            s++;
        }
        //dbg(d);
        done[d] = true;
        gc.push_back(make_pair(s, close));
    }
    int ans = 0;
    sort(gc.begin(), gc.end(), comp);
    for (auto c : gc)
    {
        if (c.first >= m)
        {
            ans++;
        }
        if (c.second == 1 && k > 0)
        {
            k--;
            c.second = 0;
        }
        if (c.second == 0)
        {
            while (c.first >= 2 * m && k > 0)
            {
                k--;
                ans++;
                c.first -= m;
            }
        }
    }
    cout << ans;
}
