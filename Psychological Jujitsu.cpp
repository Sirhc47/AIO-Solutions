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
    file(psych);
    vector<int> cards(13);
    map<int, int> cts;
    int a, b;
    for (int i = 0; i < 13; i++){
        cin >> cards[i];
        cts[cards[i]] = i+1;
        //dbg(i);
    }
    int highscore = 0;
    for (int i = 13; i >= 1; i--){
        int score = 0;
        int en = 0;
        en = cts[i];
        for (int j = i-1; j >= 1; j--){
            score += cts[j];
        }
        int diff = score-en;
        //dbg(diff);
        if (diff > highscore){
            highscore = diff;
        }
    }
    cout << highscore;
}
