#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream in("wetin.txt");
    ofstream out("wetout.txt");
    int water = 0;
    int rain;
    for (int i = 0; i < 8; i++){
        in >> rain;
        water += rain;
        water = max(0, water-10);
    }
    out << water;
}
