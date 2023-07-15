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
    file(frog);
    int n, k;
    cin >> n >> k;
    vector<int> dist(n - 1);
    long long sum = 0;
    vector<int> absdist(n - 1);
    vector<int> reldist(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> dist[i];
        sum += dist[i];
        absdist[i] = sum;
        reldist[i] = (k * (i + 1) - sum);
    }
    long long moves = 0;
    long long edge = (n - 1) * k - sum;
    vector<int> weights = reldist;
    sort(reldist.begin(), reldist.end()); // reduce sum of absolute
    long long movefirst = 0;
    long long movelast = 0;
    long long target;
    // 0 to edge, whichever is closer to median
    long long minans = LLONG_MAX;
    for (target = reldist[(n - 2) / 2] - 1; target <= reldist[n / 2] + 1; target++)
    {
        // dbg(target);
        movefirst = target;
        movelast = edge - movefirst;
        weights[n - 2] -= movelast;
        long long ans = 0;
        for (auto c : weights)
        {
            ans += abs(c - movefirst);
        }
        ans += abs(movefirst);
        ans += abs(movelast);
        // dbg(ans);
        weights[n - 2] += movelast;
        minans = min(ans, minans);
    }
    cout << minans;
}
