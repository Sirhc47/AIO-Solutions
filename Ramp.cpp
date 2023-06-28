#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <stack>
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
    vector<int> days;
    int x;
    int streak = 1;
    int maxstreak = 0;
    int cur;
    for (int i = 0; i < n; i++){
        cin >> x;
        days.push_back(x);
    }
    cur = days[0];
    for (int i = 1; i<n; i++){
        if (days[i] == cur + 1){
            streak++;
        }
        else{
            if (streak > maxstreak){
                maxstreak = streak;
            }
            streak = 1;
        }
        cur = days[i];
    }
    if (streak > maxstreak)
    {
        maxstreak = streak;
    }
    cout << maxstreak;
}
