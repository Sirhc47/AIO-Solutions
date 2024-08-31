#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ifstream fin("shopin.txt");
    ofstream fout("shopout.txt");
    int n, k;
    fin >> n >> k;
    vector<int> c(n);
    for (int i = 0; i < n; i++){
        fin >> c[i];
    }
    long long ans = 0;
    for (int i = 0; i < k; i++){
        ans += c[i];
    }
    int idx = n-k-1;
    for (int i = k; i < n/2; i++){
        ans += c[idx];
        idx-=2;
    }
    fout << ans;
    return 0;
}
