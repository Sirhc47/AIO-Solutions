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
int main()
{
    file(goss);
    int n; cin >> n;
    vector<set<int>> groups;
    map<int, int> ftg;
    int a, b;
    while (cin >> a >> b){
        if (a == -1 && b == -1){
            break;
        }
        if (ftg.count(a) && ftg.count(b)){
            //cout << "merge\n";
            if (ftg[a] != ftg[b]){
                set<int> t = groups[ftg[b]];
                groups[ftg[a]].merge(groups[ftg[b]]);
                for (auto c : t){
                    ftg[c] = ftg[a];
                }
            }
        }
        else if (ftg.count(a)){
            //cout << "a\n";
            groups[ftg[a]].insert(b);
            ftg[b] = ftg[a];
        }
        else if (ftg.count(b)){
            //cout << "b\n";
            groups[ftg[b]].insert(a);
            ftg[a] = ftg[b];
        }
        else{
            //cout << "new\n";
            set<int> temp = {};
            temp.insert(a);
            temp.insert(b);
            groups.push_back(temp);
            ftg[a] = groups.size()-1;
            ftg[b] = ftg[a];
        }
        
    }
    int sus = 0;
    while (cin >> a >> b){
        if (a == -1 && b == -1){
            break;
        }
        sus = 0;
        for (int i = 0; i < groups.size(); i++){
            if (groups[i].count(a) && groups[i].count(b)){
                cout << "yes\n";
                sus = 1;
                break;
            }
        }
        if (sus == 0){
            cout << "no\n";
        }
    }
}
