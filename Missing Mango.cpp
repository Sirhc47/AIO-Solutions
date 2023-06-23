#include <iostream>
#include <fstream>
using namespace std;
 
 
int main()
{
    int ix;
    int id;
    int cx;
    int cd;
    int i1;
    int i2;
    int c1;
    int c2;
    int ans;
    ifstream inputfile("manin.txt");
    ofstream outputfile("manout.txt");
    inputfile >> ix >> cx >> id >> cd;
    i1 = ix - id;
    i2 = ix + id;
    c1 = cx - cd;
    c2 = cx + cd;
    if (i1 == c1) {
        ans = i1;
    }
    if (i1 == c2) {
        ans = i1;
    }
    if (i2 == c1){
        ans = i2;
    }
    if (i2 == c2){
        ans = i2;
    }
    outputfile << ans << "\n";
    inputfile.close();
    outputfile.close();
    return 0;
}
