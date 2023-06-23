#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace::std;
int main()
{
    //Shortest even and shortest odd path to a city
    ifstream input("evadingin.txt");
    ofstream output("evadingout.txt");
    map<int, set<int>> neighbours;
    int n, e, x, k;
    input >> n >> e >> x >> k;
    vector<int> even(n + 1, 1000000005);
    vector<int> odd(n + 1, 1000000005);
    set<int> codd;
    set<int> ceven;
    int a;
    int b;
    for (int i = 0; i < e; i++) {
        input >> a;
        input >> b;
        neighbours[a].insert(b);
        neighbours[b].insert(a);
    }
    even[x] = 0;
    for (auto s : neighbours[x]) {
        odd[s] = 1;
        codd.insert(s);
    }
    //can be optimised a ton. stop going over cities already done.
    bool state = true;
    while (state) {
        state = false;
        for (auto s : codd) {
            for (auto q : neighbours[s]) {
                if (odd[s] + 1 < even[q]) {
                    even[q] = odd[s] + 1;
                    ceven.insert(q);
                    state = true;
                }
            }
        }
        codd.clear();
        for (auto s : ceven) {
            for (auto q : neighbours[s]) {
                if (even[s] + 1 < odd[q]) {
                    odd[q] = even[s] + 1;
                    codd.insert(q);
                    state = true;
                }
            }
        }
        ceven.clear();
    }
    int ans = 0;
    if (k % 2 == 0) {
        for (int i = 0; i < n+1; i++) {
            if (even[i] <= k) {
                ans++;
            }
        }
    }
    else {
        for (int i = 0; i < n+1; i++) {
            if (odd[i] <= k) {
                ans++;
            }
        }
 
    }
    cout << ans;
    output << ans;
 
 
}
