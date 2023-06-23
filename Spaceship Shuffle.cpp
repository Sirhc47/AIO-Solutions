#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#define dbg(x) cout << '>' << #x << ':' << x << endl;
using namespace ::std;
int main()
{
    ifstream input("spacein.txt");
    ofstream output("spaceout.txt");
    int n;
    input >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<long long> diff(n);
    vector<long long> amogus;
    long long x = 0;
    for (int i = 0; i < n; i++)
    {
        input >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        input >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        diff[i] = a[i] - b[i];
        x+= diff[i];
        amogus.push_back(x);
    }
    long long mindist = 0;
    sort(amogus.begin(), amogus.end());
    long long subtract = amogus[(amogus.size() - 1) / 2];
    for (long long i = 0; i < amogus.size(); i++)
    {
        mindist += abs(amogus[i] - subtract);
    }
    output << mindist;
}
