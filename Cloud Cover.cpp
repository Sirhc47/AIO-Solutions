#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;
int main()
{
    ifstream input("cloudin.txt");
    ofstream output("cloudout.txt");
    int n;
    int k;
    input >> n >> k;
    int min = 0;
    vector<int> people (n,0);
 
 
    for (int i = 0; i < n; i++) {
        input >> people[i];
    }
    for (int i = 0; i < k; i++) {
        min += people[i];
    }
    int current = min;
    cout << current << "\n";
    for (int i = k; i < n-1; i++) {
        current += people[i];
        current -= people[i - k];
        cout << current << "\n";
        if (current < min) {
            min = current;
        }
    }
    output << min;
 
}
