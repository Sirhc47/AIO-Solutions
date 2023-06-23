#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace::std;
int main()
{
    ifstream input("hirein.txt");
    ofstream output("hireout.txt");
    int n;
    int s;
    int m;
    input >> n;
    vector<int> skill(n, 0);
    for (int i = 0; i < n; i++) {
        input >> skill[i];
    }
    input >> s;
    vector<int> student(s, 0);
    for (int i = 0; i < s; i++) {
        input >> student[i];
    }
    input >> m;
    vector<int> master(m, 0);
    for (int i = 0; i < m; i++) {
        input >> master[i];
    }
    sort(skill.begin(), skill.end());
    sort(student.begin(), student.end());
    sort(master.begin(), master.end());
    int st = 0;
    int ma = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        while (st < s && student[st] < skill[i]) {
            st++;
        }
        if (st == s) {
            break;
        }
        st++;
        count++;
 
    }
    sort(master.begin(), master.end(), greater<int>());
    sort(skill.begin(), skill.end(), greater<int>());
    for (int i = 0; i < n; i++) {
        while (ma < m && master[ma] > skill[i]) {
            ma++;
        }
        if (ma == m) {
            break;
        }
        ma++;
        count++;
    }
    output << min(count, n);
 
}
