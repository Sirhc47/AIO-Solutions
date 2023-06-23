#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <cmath>
using namespace::std;
int main()
{
    ifstream input("tennisin.txt");
    ofstream output("tennisout.txt");
    int b;
    int n;
    int ans;
    vector<int> a;
    vector<int> remainder;
    int z;
    int totalsubtract = 0;
    input >> b >> n;
    for (int i = 0; i < b; i++) {
        input >> z;
        a.push_back(z);
        remainder.push_back(z);
    }
    sort(remainder.begin(), remainder.end());
    int subtract = *min_element(remainder.begin(), remainder.end());
    int current = subtract;
    int j = 1;
    int diff;
    int left = remainder.size();
    int k = 0;
    vector<int> minimums(1, subtract);
    for (int i = 1; i < remainder.size(); i++) {
        diff = remainder[i] - current;
        if (diff > 0) {
            minimums.push_back(diff);
            current = remainder[i];
        }
    }
    while (n > subtract * left) {
        n -= subtract * left;
        totalsubtract += subtract;
        for (int i = k; i < remainder.size(); i++) {
            remainder[i] -= subtract;
            if (remainder[i] == 0) {
                k = i;
                left--;
            }
        }
        subtract = minimums[j];
        j++;
    }
    vector<int> safe;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > totalsubtract) {
            safe.push_back(i);
        }
    }
    int as = (n - 1) % safe.size();
    ans = safe[as] + 1;
    output << ans;
    output.close();
    input.close();
    return 0;
}
