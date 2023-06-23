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
int main(){
    file(frog);
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<int> left(n);
    vector<int> right(n);
    left[0] = 0;
    int low = INT32_MAX;
    for (int i = 0; i < n; i++){
        if (v[i] < low){
            low = v[i];
        }
        if (i != 0){
            left[i] = v[i]-low;
        }
    }
    right[n-1] = 0;
    low = INT32_MAX;
    for (int i = n-1; i >= 0; i--){
        if (v[i] < low){
            low = v[i];
        }
        right[i] = v[i]-low;
    }
    int ans = 0;
    for (int i = 1; i < n-1; i++){
        if (left[i]+right[i]>ans && left[i] > 0 && right[i] > 0){
            ans = left[i] +right[i];
        }
    }
    cout << ans;
}
