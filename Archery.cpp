#include <iostream>
#include <fstream>
using namespace std;
int main(){
    int a, b, c;
    ifstream input("archin.txt");
    ofstream output("archout.txt");
    input >> a >> b >> c;
    output << max(a-((a-b)+(a-c)),1) << " " << min(b-1+c,a);
}
