#include <iostream>
#include <fstream>
#include <cmath>
using namespace::std;
int main(){
    ifstream input("magicin.txt");
    ofstream output("magicout.txt");
    int a, b, x;
    int c, d, e;
    int f, g, h;
    input >> a >> b >> c;
    x = 20 - a - b;
    h = a;
    g = c;
    e = b;
    d = 20 - b - g;
    f = 20 - a - c;
    output << a << " " << b << " " << x << "\n";
    output << c << " " << d << " " << e << "\n";
    output << f << " " << g << " " << h << "\n";
}
