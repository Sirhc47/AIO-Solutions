#include <iostream>
#include <fstream>
using namespace std;
 
int main()
{
    int x;
    int y;
    int ans;
    ifstream inputFile("addin.txt");
    ofstream outputFile("addout.txt");
    inputFile >> x >> y;
    ans = x + y;
    outputFile << ans << "\n";
    inputFile.close();
    outputFile.close();
    return 0;
}
