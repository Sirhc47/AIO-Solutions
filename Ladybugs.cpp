#include <fstream>
#include <iostream>
using namespace std;
int main(){
    int n;
    ifstream fin("ladyin.txt");
    ofstream fout("ladyout.txt");
    fin >> n;
    long long small = INT64_MAX;
    long long big = 0;
    int x;
    for (int i = 0; i < n; i++){
        fin >> x;
        if (x > big){
            big = x;
        }
        if (x < small){
            small = x;
        }
    }
    fout << big-small+1;
}
