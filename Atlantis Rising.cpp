#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    ifstream fin("atlanin.txt");
    ofstream fout("atlanout.txt");
    fin >> n;
    int x;
    int ans = 0;
    vector<int> heights;
    vector<bool> left(n, 0);
    int heighest = 0;
    for (int i = 0; i < n; i++){
        fin >> x;
        if (x > heighest){
            heighest = x;
        }
        if (x < heighest){
            left[i] = true;
        }
        heights.push_back(x);
    }
    reverse(heights.begin(), heights.end());
    heighest = 0;
    for (int i = 0; i < n; i++)
    {
        if (heights[i] > heighest)
        {
            heighest = heights[i];
        }
        if (heights[i] < heighest && left[n-i-1]==true)
        {
            ans++;
            cout << n-i << "\n";
        }
    }
    fout << ans;
}
