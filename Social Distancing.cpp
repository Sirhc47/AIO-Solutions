#include <vector>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    int k;
    ifstream input("distin.txt");
    ofstream output("distout.txt");
    input >> n;
    cout << n;
    input >> k;
    vector<int> d(n,0);
    for (int i = 0; i < n; i++) {
        input >> d[i];
    }
    int count;
    int current;
    sort(d.begin(), d.end()); //sort doesnt work
    current = d[0];
    count = 1;
    for (int i = 1; i < n; i++) {
        if (d[i] - current >= k) {
            count++;
            current = d[i];
        }
    }
    output << count;
    output.close();
    input.close();
    return 0;
 
 
 
 
}
