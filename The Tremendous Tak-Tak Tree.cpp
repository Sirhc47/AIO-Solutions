#include <iostream>
#include <fstream>
using namespace std;
int main(){
    int n;
    ifstream input("taktakin.txt");
    ofstream output("taktakout.txt");
    int wait = 0;
    input >> n;
    while ((n-1)%11 != 0){
        n*=2;
        wait++;
    }
    output << wait << " " << n;
}
