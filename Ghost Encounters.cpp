#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
using namespace::std;
 
int main()
{
    ifstream input("ghostin.txt");
    ofstream output("ghostout.txt");
    int n;
    int k;
    map<int, int> count;
    vector<int> x;
    vector<int> t;
    input >> n >> k;
    int z;
    for (int i = 0; i < n; i++) {
        input >> z;
        x.push_back(z);
        input >> z;
        t.push_back(z);
    }
    for (int i = 0; i < n; i++) {
        count[k * x[i] - t[i]]++;
    }
    int max = 0;
    map<int, int>::iterator it = count.begin();
    while (it != count.end()) {
        if (it->second > max) {
            max = it->second;
        }
        it++;
    }
    output << max;
    output.close();
    input.close();
    return 0;
 
}
