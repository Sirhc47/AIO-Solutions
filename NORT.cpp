#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream input("nortin.txt");
    ofstream output("nortout.txt");
    int x, y;
    input >> x >> y;
    int ans = x*y;
    if (x % 2 == 1 && y % 2 == 1){
        ans--;
    }
    output << ans;
}
