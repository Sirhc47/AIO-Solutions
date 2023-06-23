#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int f;
    ifstream input("listin.txt");
    ofstream output("listout.txt");
    input >> f;
    int a, b;
    map<int, int> friends;
    for (int i = 0; i < f; i++){
        input >> a >> b;
        friends[a]++;
        friends[b]++;
    }
    vector<int> wins;
    int maxw = 0;
    for (auto c : friends){
        if (c.second > maxw){
            maxw = c.second;
        }
    }
    for (auto c : friends){
        if (c.second == maxw){
            wins.push_back(c.first);
        }
    }
    sort(wins.begin(), wins.end());
    for (int i = 0; i < wins.size(); i++){
        output << wins[i] << "\n";
    }
}
