#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
int main(){
    ifstream input("tripin.txt");
    ofstream output("tripout.txt");
    int n;
    input >> n;
    vector<int> nums;
    nums.push_back(0);
    int x;
    int k = 0;
    for (int i = 0; i < n; i++){
        input >> x;
        nums.push_back(x);
        if (x%3 == 0){
            k++;
        }
    }
    if (k == 0){
        output << "Nothing here!";
        return 0;
    }
    output << k << "\n";
    for (int i = 1; i <= n; i++){
        if (nums[i]%3 == 0){
            output << i << " ";
        }
    }
 
}
