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
    file(safe);
    int a, b;
    cin >> a >> b;
    vector<int> mum(a);
    vector<int> known(b);
    vector<int> md(a-1);
    vector<int> kd(b-1);
    for (int i = 0; i < a; i++){
        cin >> mum[i];
        if (i != 0){
            md[i-1] = mum[i]-mum[i-1];
        }
    }
    for (int i = 0; i < b; i++){
        cin >> known[i];
        if (i != 0)
        {
            kd[i-1] = known[i] - known[i - 1];
        }
    }
    //so braindead didn't realise it can't be negative diff
    int key = 0;
    int sus = 0;
    int diff = 0;
    for (int i = 0; i< a-b+1; i++){
        sus = 1;
        for (int j = 0; j < kd.size(); j++){
            if (kd[j] != md[i+j]){
                sus = 0;
                break;
            }
        }
        if (sus == 1){
            diff = mum[i]-known[0];
            if (diff >= 0){
                break;
            }
        }
    }
    for (int i = 0; i < a; i++){
        cout << mum[i]-diff << "\n";
    }
 
}
