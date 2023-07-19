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
    file(rest);  
    int n; cin >> n;
    vector<int> d(n);
    long long amount = 0;
    for (int i = 0; i < n; i++){
        cin >> d[i];
        amount+=d[i];
    }
    int m;
    cin >> m;
    vector<int> r(m);   
    for (int i = 0; i < m; i++){
        cin >> r[i];
    }
    sort(r.begin(), r.end());
    int seated = 0;
    sort(d.rbegin(), d.rend());
    vector<int> levels(101);
    int valid = m;
    int j = 0;
    for (int i = 0; i<=100; i++){
        //find number of restaurants with greater than or equal to i seats
        while (j < m && r[j] < i){
            j++;
            valid--;
        }
        if (valid == 0){
            break;
        }
        levels[i] = valid;
    }
    long long miss = 0;
    int rem = 0;
    long long sat = 0;
    int currentlevel = 1;
    int start = 0;
    int end = 0;
    int top = r[m-1];
    for (int i = 0; i < n; i++){
        start = end;
        //dbg(d[i]);
        //dbg(start);
        //dbg(currentlevel);
        if (d[i] >= levels[currentlevel]-start){
            sat+=levels[currentlevel]-start;
            d[i]-=levels[currentlevel]-start;
            currentlevel++;
            //stop at top level
            if (currentlevel > top){
                break;
            }

            sat += min(start, d[i]);
            end = min(start, d[i]);
/*             if (end == levels[currentlevel]){
                end = 0;
                currentlevel++;
            } */
        }
        else{
            sat+=d[i];
            end=start+d[i];
        }
        //dbg(sat);
        //cout << "\n";
        

    }
    cout << amount - sat;
}
