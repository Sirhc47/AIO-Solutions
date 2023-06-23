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
using namespace std;
int main()
{
    file(queues);
    vector<int> q;
    int x;
    while (cin >> x){
        if (x == -2){
            break;
        }
        if (x == -1){
            q.erase(q.begin());
        }
        else{
            q.push_back(x);
        }
        if (q.size() == 0){
            cout << "queue is empty!\n";
        }
        else{
            for (auto c : q){
                cout << c << " ";
            }
            cout << "\n";
        }
    }
 
}
