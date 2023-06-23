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
bool compare(int a, int b){
    return (abs(a) < abs(b));
}
int main()
{
    file(sort);
    int n;
    cin >> n;
    vector<int> list(n);
    for (int i = 0; i < n; i++){
        cin >> list[i];
    }
    sort(list.begin(), list.end(), compare);
    for (int i = 0; i < n; i++){
        cout << list[i] << "\n";
    }
}
