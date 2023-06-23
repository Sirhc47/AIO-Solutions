#include <fstream>
#include <vector>
#include <iostream>
#include <map>
using namespace::std;
int main()
{
    ifstream input("cavalryin.txt");
    ofstream output("cavalryout.txt");
    vector<int> knights(100003, 0);
    vector<int> a;
    int n;
    input >> n;
    int x;
    for (int i = 0; i < n; i++) {
        input >> x;
        knights[x]++;
    }
    string ans = "YES";
    for (int i = 1; i < knights.size(); i++) {
        if (knights[i]%i != 0) {
            ans = "NO";
        }
    }
    output << ans;
}
