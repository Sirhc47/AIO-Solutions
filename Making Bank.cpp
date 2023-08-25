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
#define speed() \
    ios::sync_with_stdio(false); \
    cin.tie(0)
#define file(name) \
    speed(); \
    freopen(#name "in.txt", "r", stdin); \
    freopen(#name "out.txt", "w", stdout)
#define dbg(x) cout << '>' << #x << ':' << x << endl;
using namespace std;
int main() {
    ifstream fin("bankin.txt");
    ofstream fout("bankout.txt");
    int n; fin >> n;
    char x;
    vector<char> days;
    int s = 1;
    for (int i = 0; i < n; i++){
        fin >> x;
        days.push_back(x);
    }
    int money = 0;
    for (int i = 0; i < n; i++){
        if (days[i] == 'M'){
            money+=s;
        }
        else{
            if (n-i > s){
                s++;
            }
            else{
                money+=s;
            }
        }
    }
    fout << money;
    return 0;
}
