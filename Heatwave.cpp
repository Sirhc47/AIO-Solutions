#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main(){
    int n, h;
    ifstream input("heatin.txt");
    ofstream output("heatout.txt");
    input >> n >> h;
    int maxstreak = 0;
    int currentstreak = 0;
    int x;
    for (int i = 0; i < n; i++){
        input >> x;
        if (x >= h){
            currentstreak++;
        }
        else{
            if (currentstreak > maxstreak){
                maxstreak = currentstreak;
            }
            currentstreak = 0;
        }
    }
    if (currentstreak > maxstreak)
    {
        maxstreak = currentstreak;
    }
    output << maxstreak;
}
