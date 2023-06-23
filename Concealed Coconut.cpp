#include <fstream>
#include <iostream>
#include <cmath>
using namespace::std;
int main()
{
    ifstream input("cocoin.txt");
    ofstream output("cocoout.txt");
    int a, b, c, d, e, f;
    input >> a >> b >> c >> d >> e >> f;
    if (pow(a - d, 2) + pow(b - e, 2) > pow(c + f, 2)||sqrt(pow(a-d,2)+pow(b-e,2))+min(c,f)< max(c,f)) {
        output << "no";
    }
    else {
        output << "yes";
    }
}
