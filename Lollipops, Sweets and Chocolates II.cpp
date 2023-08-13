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
    file(lsc);
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> stores(n);
    vector<int> houses(m);
    map<int, int> p; //increasing order not matching with houses
    for (int i = 0; i < n; i++){
        cin >> stores[i];
    }
    for (int i = 0; i < m; i++){
        cin >> houses[i];
    }
    int x;
    for (int i = 0; i < m; i++){
        cin >> p[i];
    }
    //use a binary search and go through all the houses each time, then check if equal to p
    int low = 0;
    int high = l;

    while (low <= high){
        vector<int> dist;
        int mid = (low+high)/2;

        
        for (int i = 0; i < m; i++){
            int temp = 0;
            int start = lower_bound(stores.begin(), stores.end(), houses[i]-mid)-stores.begin();
            int end = upper_bound(stores.begin(), stores.end(), houses[i]+mid)-stores.begin();
            temp = end-start;
            dist.push_back(temp);
        }
        sort(dist.begin(), dist.end());
        bool amogus = false;
        for (int i = 0; i < m; i++){
            if (dist[i] > p[i]){
                high = mid-1;
                amogus = true;
                break;
            }
            else if (dist[i] < p[i]){
                low = mid+1;
                amogus = true;
                break;
            }
        }
        if (!amogus){
            cout << mid;
            return 0;
        }
    }
    cout << -1;
    return 0;



}
