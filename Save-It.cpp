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
    file(save);
    int n; cin >> n;
    vector<int> prices(n);
    map<int, int> md;
    long long total = 0;
    for (int i = 0; i < n; i++){
        cin >> prices[i];
        total += prices[i];
        md[prices[i]%5]++;
    }
    //1,1  3,4
    long long savings = 0;
    savings += md[1];
    md[1] = 0;
    savings += 2*(min(md[3], md[4]));
    int temp = min(md[3], md[4]);
    md[3] -= temp;
    md[4] -= temp;
    savings += 2*md[2];
    md[2] = 0;
    if (md[3] != 0){
        savings += md[3]/2;
        md[3] = md[3]%2;
        savings -= 2*md[3];
    }
    if (md[4] != 0){
        savings += 2*(md[4]/3);
        md[4] = md[4]%3;
        savings -= md[4];
    }
    //cout << "savings: " << savings << "\n";
    cout << total-savings;
 
}
