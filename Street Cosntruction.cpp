#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace::std;
int d(int a, int b) {
    int x = a / b;
    if (x * b < a) {
        return x + 1;
    }
    else {
        return x;
    }
 
}
int main()
{
    ifstream input("streetin.txt");
    ofstream output("streetout.txt");
    int n;
    int k;
    input >> n >> k;
    int empty = n - k;
    int ans = d(empty, k + 1);
    output << ans;
}
