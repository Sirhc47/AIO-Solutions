#include <iostream>
#include <fstream>
using namespace std;
int main(){
    int n;
    ifstream input("postin.txt");
    ofstream output("postout.txt");
    input >> n;
    int x, w;
    int left = 0;
    int right = 20000000;
    int ans;
    for (int i = 0; i < n; i++){
        input >> x >> w;
        if (x < left){
            left = x;
            right = x + w;
            ans = i;
        }
        else if (x+w>left && x < right){
            left = x;
            right = x+w;
            ans = i;
        }
 
    }
    output << ans+1;
}
