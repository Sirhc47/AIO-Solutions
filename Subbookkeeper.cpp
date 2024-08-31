#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define ll long long
using namespace std;
int main()
{
    ifstream fin("bookin.txt");
    ofstream fout("bookout.txt");
    int n;
    fin >> n;
    string s;
    fin >> s;
    int score = 0;
    char cur = '.';
    int qind;
    for (int i = 0; i < n; i++){
        if (s[i] == '?'){
            qind = i;
        }
        if (s[i] == cur){
            score++;
        }
        else{
            cur = s[i];
        }
    }
    if (qind == 0 || qind == n-1){
        score++;
    }
    else{
        char before = s[qind-1];
        char after = s[qind+1];
        if (before == after){
            score+=2;
        }
        else{
            score++;
        }
    }
    fout << score;
    return 0;
}
