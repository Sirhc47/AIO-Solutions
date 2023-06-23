#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
int main(){
    ifstream input("ninjain.txt");
    ofstream output("ninjaout.txt");
    int a, b;
    input >> a >> b;
    output << a-ceil(float(a)/float((b+1)));
}
