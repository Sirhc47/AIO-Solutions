#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main(){
    ifstream input("dancein.txt");
    ofstream output("danceout.txt");
    int d, t;
    input >> d >> t;
    vector<int> hoops(d+1);
    int i, j;
    int ans = 0;
    for (int l = 0; l < t; l++){
        input >> i >> j;
        if (hoops[i] <= 0){
            ans++;
            hoops[i]++;
            cout << i << "\n";
        }
        hoops[i]--;
        hoops[j]++;
    }
    output << ans;
 
}
