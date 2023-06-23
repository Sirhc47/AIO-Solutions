#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream input("hailin.txt");
    ofstream output("hailout.txt");
    int x;
    int count;
    while (input >> x){
        count = 0;
        if (x == 0){
            break;
        }
        while (x!=1){
            if (x%2 == 0){
                x/=2;
            }
            else{
                x=3*x+1;
            }
            count++;
        }
        output << count << "\n";
    }
}
