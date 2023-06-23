#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream Input("vasesin.txt");
    ofstream Output("vasesout.txt");
    int x;
    int y;
    Input >> x;
    if (x < 6) {
        Output << "0 0 0";
    }
    else {
        y = x - 3;
        Output << "1 2 " << y;
    }
    Input.close();
    Output.close();
    return 0;
}
