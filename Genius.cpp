#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
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
    int n, p;
    file(gen);
    cin >> n >> p;
    map<int,int> score;
    for (int i = 1; i <= n; i++){
        score[i] = 0;
    }
    int turn = 0;
    while(1){
        for (int i = 1; i<= n; i++){
            if (p > 0){
                turn++;
                int temp = min(p, turn);
                p-= temp;
                score[i]+=temp;
            }
            else{
                goto exit;
            }
        }
    }
    exit:
    auto it = max_element(score.begin(), score.end(), [](auto a, auto b)
                          { return a.second < b.second; });
    cout << it->first << ' ' << it->second << '\n';
 
}
