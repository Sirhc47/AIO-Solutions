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
    file(swaps);
    int n;
    cin >> n;
    vector<long double> v;
    v.reserve(n);
    for (int i = 0; i < n; i++)
    {
        long double x;
        cin >> x;
        v.push_back(x);
    }
    for (auto it = v.begin(); it != v.end(); it++)
    {
        auto me = max_element(it, v.end());
        swap(*it, *me);
        if (it != me)
            cout << it - v.begin() + 1 << ' ' << me - v.begin() + 1 << '\n';
    }
    cout << "all sorted\n";
}
