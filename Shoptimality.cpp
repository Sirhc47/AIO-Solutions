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
    file(shop);
    int n, m;
    cin >> n >> m;
    vector<int> houseLocations(n);
    for (int i = 0; i < n; i++){
        cin >> houseLocations[i];
    }
    vector<int> shopLocations(m);
    for (int i = 0; i < m; i++){
        cin >> shopLocations[i];
    }
    vector<int> shopPrices(m);
    for (int i = 0; i < m; i++){
        cin >> shopPrices[i];
    }
    
    //find the best shop from the position of each shop
    //then find for each house the best shop

    vector<pair<int, int>> p(m, {0, 0});
    p[0] = {shopPrices[0], 0};
    for (int i = 1; i < m; i++){
        p[i] = {min(p[i-1].first + abs(shopLocations[i] - shopLocations[i-1]), shopPrices[i]), 0};
    }
    p[m-1] = {p[m-1].first, shopPrices[m-1]};
    for (int i = m-2; i >=0; i--){
        p[i] = {p[i].first, min(p[i+1].second + abs(shopLocations[i] - shopLocations[i+1]), shopPrices[i])};
    }


    for (int i = 0; i < n; i++){
        //leftshop is index of shop with location < houseLocations[i]
        //rightshop is index of shop with location > houseLocations[i]
        int leftshop = lower_bound(shopLocations.begin(), shopLocations.end(), houseLocations[i]) - shopLocations.begin() - 1;
        int rightshop = upper_bound(shopLocations.begin(), shopLocations.end(), houseLocations[i]) - shopLocations.begin();
        
        if (leftshop < 0){
            cout << (p[rightshop].second + abs(houseLocations[i]-shopLocations[rightshop])) << " ";
        }
        else if (rightshop >= m){
            cout << (p[leftshop].first + abs(houseLocations[i]-shopLocations[leftshop])) << " ";
        }
        else{
            cout << (min(p[rightshop].second + abs(houseLocations[i] - shopLocations[rightshop]), p[leftshop].first + abs(houseLocations[i] - shopLocations[leftshop]))) << " ";
        }  
    }

    return 0;
}
