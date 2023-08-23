#include <algorithm>
#include <fstream>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <list>
using namespace::std;
int main()
{
    int n;
    int k;
    //k is required signatures
    int q;
    int x;
    int c = 0;
    vector<int> p;
    vector<int> d;
    vector<int> ans;
    ifstream input("ladyin.txt");
    ofstream output("ladyout.txt");
    input >> n >> k >> q;
    map<int,int> b;
    for (int i = 0; i < n; i++) {
        input >> x;
        p.push_back(x);
    }
    for (int i = 0; i < q; i++) {
        input >> x;
        d.push_back(x);
    }
    b[p[0]] = p[k - 1]-p[0];
    for (int i = 1; i < n; i++) {
        if (k + i <= p.size()) {
            b[p[i]] = min(p[k - 1 + i] - p[i], p[i] - p[i - 1] + b[p[i - 1]]);
        }
        else {
            b[p[i]] = p[i] - p[i - 1] + b[p[i - 1]];
        }
    }
    reverse(p.begin(),p.end());
    map<int, int>f;
    f[p[0]] = p[0] - p[k-1];
    for (int i = 1; i < n; i++) {
        if (k + i-1 < p.size()) {
            f[p[i]] = min(-(p[k - 1 + i] - p[i]), -(p[i] - p[i - 1] - f[p[i - 1]]));
        }
        else {
            f[p[i]] = -(p[i] - p[i - 1] - f[p[i - 1]]);
        }
    }
    map<int,int> final;
    for (int i = 0; i < n; i++) {
        final[p[i]] = min(f[p[i]], b[p[i]]);
    }
 
    reverse(p.begin(),p.end());
    int close;
    int lower;
    int upper;
    vector<int>::iterator above;
    for (int i = 0; i < q; i++) {
        //Find closest p to d[i]
        above = lower_bound(p.begin(), p.end(), d[i]);
        upper = above - p.begin();
        if (upper >= p.size()) {
            upper = p.size() - 1;
        }
        if (upper != 0) {
            lower = upper - 1;
            //Not based on distance but based on less distance required to travel
            if (p[upper] - d[i]+final[p[upper]] < d[i] - p[lower]+final[p[lower]]) {
                close = p[upper];
            }
            else {
                close = p[lower];
            }
        }
        else {
            close = p[upper];
        }
        ans.push_back(final[close] + abs(d[i] - close));
        
    }
 
 
    for (int i = 0; i < ans.size(); i++) {
        output << ans[i] << " ";
    }
    input.close();
    output.close();
    return 0;
    
}
