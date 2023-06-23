#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main(){
    ifstream input("phonein.txt");
    ofstream output("phoneout.txt");
    int n;
    int l, f, r;
    input >> n;
    int left = 0;
    int right = 0;
    vector<int> lv;
    vector<int> fv;
    vector<int> rv;
    for (int i = 0; i < n-1; i++){
        input >> l >> f >> r;
        lv.push_back(l);
        fv.push_back(f);
        rv.push_back(r);
    }
    input >> f;
    fv.push_back(f);
    int templeft;
    int tempright;
    right = fv[0];
    cout << left << " " << right << "\n";
    for (int i = 0; i < n-1; i++){
        templeft = min(left+lv[i]+fv[i+1], right+rv[i]);
        tempright = min(right+fv[i+1]+rv[i], left+lv[i]);
        cout << tempright << "sdfsdfsd\n";
        left = templeft;
        right = tempright;
        cout << left << " " << right << "\n";
    }
    int ans = min(left+fv[n-1], right);
    output << ans;
}
