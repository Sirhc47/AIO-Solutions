#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, q;
    ifstream input("encyin.txt");
    ofstream output("encyout.txt");
    input >> n >> q;
    vector<int> words;
    words.push_back(0);
    int x;
    for (int i = 0; i < n; i++){
        input >> x;
        words.push_back(x);
    }
    for (int i = 0; i < q; i++){
        input >> x;
        output << words[x] << "\n";
    }
}
