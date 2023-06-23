#include <iostream>
#include <fstream>
using namespace::std;
int main()
{
    ifstream input("salesin.txt");
    ofstream output("salesout.txt");
    int a, b, c;
    input >> a >> b >> c;
    int x = min(a, min(b, c));
    output << a + b + c - x;
}
