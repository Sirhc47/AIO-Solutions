#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main(){
    int c, n ,k;
    ifstream input("chairsin.txt");
    ofstream output("chairsout.txt");
    input >> c >> n >> k;
    vector<int> wet(c);
    vector<int> dryseats;
    char x;
    for (int i = 0; i < c; i++){
        input >> x;
        if (x == 'w'){
            wet[i] = 1;
        }
        else{
            dryseats.push_back(i);
        }
    }
    int dry = n - k;
    int mindist = INT32_MAX;
    if (dry == 0){
        output << n;
        return 0;
    }
    for (int i = 0; i+dry<= dryseats.size(); i++){ //fix dry = 0
        if (dryseats[i+dry-1] - dryseats[i]+1 < mindist){
            mindist = dryseats[i + dry - 1] - dryseats[i]+1;
        }
    }
    output << max(mindist, n);
}