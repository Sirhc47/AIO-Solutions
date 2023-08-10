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
    file(island);
    int n, l;
    cin >> n >> l;
    if (n == 0 || l == 0){
        cout << 0;
        return 0;
    }
    vector<long long> v(n);
    vector<long long> p(n);
    unsigned long long total = 0;
    unsigned long long half = 0;
    unsigned long long score = 0;
    for (int i = 0; i < n; i++){
        cin >> v[i] >> p[i];
        v[i]--;
        if (v[i] > v[0] && v[i] <= (v[0]+2*l)){
            half += p[i];
        }
        total += p[i];
        score += min(v[i]-v[0], 4*l+v[0]-v[i])*p[i];
    }
    if (n == 1){
        unsigned long long ans = l;
        ans *= p[0];
        ans *= 2;
        cout << ans;
        return 0;
    }
    unsigned long long ans = score;
    unsigned long long i1 = v[0];
    unsigned long long i2 = (v[0]+2*l)%(4*l);
    long long p1 = 0;
    long long p2 = upper_bound(v.begin(), v.end(), i2)-v.begin()-1;
    if (p2 < 0){
        p2 += n;
    }
    unsigned long long dist1;
    unsigned long long dist2;
    unsigned long long move;
    for (int i = 0; i < 200005; i++){
        dist1 = (v[(p1+1)%n]-i1%(4*l)+4*l)%(4*l);
        dist2 = (v[(p2+1)%n]-i2%(4*l)+4*l)%(4*l);
        move = min(dist1, dist2);
        score -= move*half;
        score += move*(total-half);
        ans = max(ans, score);
        if (dist1 <= dist2){
            p1++;
            half -= p[p1%n];
        }
        if (dist2 <= dist1){
            p2++;
            half += p[p2%n];
        }
        i1+=move;
        i2+=move;
    }
    cout << ans;

}
