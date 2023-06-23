#include <fstream>
#include <iostream>
#include <set>
using namespace::std;
int main()
{
    ifstream input("tagin.txt");
    ofstream output("tagout.txt");
    int n;
    int m;
    input >> n >> m;
    set<int> red = { 1 };
    set<int> blue = { 2 };
    int a;
    int b;
    for (int i = 0; i < m; i++) {
        input >> a >> b;
        if (red.count(a)) {
            red.insert(b);
        }
        else {
            blue.insert(b);
        }
    }
    output << red.size() << " " << blue.size();
    output.close();
    input.close();
    return 0;
}
