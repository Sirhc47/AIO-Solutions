#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream input("piratein.txt");
    ofstream output("pirateout.txt");
    int x, l, y;
    input >> l >> x >> y;
    output << min(x+y, 2*l-x-y);
}
