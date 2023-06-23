#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int main(){
    ifstream input("hippoin.txt");
    ofstream output("hippoout.txt");
    int n, a, b, c;
    input >> n >> a >> b >> c;
    int j, k, l, m;
    j = a-1;
    k = b-a-1;
    l = c-b-1;
    m = n-c;
    output << max(j+m,max(j,m)+max(k,l));
}
