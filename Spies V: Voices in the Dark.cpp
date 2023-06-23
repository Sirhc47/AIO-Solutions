#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
int main(){
    int j, g;
    ifstream input("spiesin.txt");
    ofstream output("spiesout.txt");
    input >> j;
    vector<bool> jean(10000005, 0);
    int a, b;
    for (int i = 0; i < j; i++){
        input >> a >> b;
        for (int k = a; k < b; k++){
            jean[k] = true;
        }
    }
    input >> g;
    int ans = 0;
    for (int i = 0; i < g; i++)
    {
        input >> a >> b;
        for (int k = a; k < b; k++)
        {
            if (jean[k] == true){
                ans++;
            }
        }
    }
    output << ans;
}
