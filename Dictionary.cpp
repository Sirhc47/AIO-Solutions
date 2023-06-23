#include <iostream>
#include <fstream>
#include <map>
#include <set>
using namespace std;
int main(){
    int d, w;
    ifstream input("dictin.txt");
    ofstream output("dictout.txt");
    input >> d >> w;
    set<int> available;
    map<int, int> dict;
    int a, b;
    for (int i = 0; i < d; i++){
        input >> a >> b;
        available.insert(a);
        dict[a] = b;
    }
    int x;
    for (int i = 0; i < w; i++){
        input >> x;
        if (available.count(x)){
            output << dict[x] << "\n";
        }
        else{
            output << "C?\n";
        }
    }
 
}
