#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main(){
    int n;
    ifstream fin("alienin.txt");
    ofstream fout("alienout.txt");
    int w;
    fin >> n >> w;
    int current = 0;
    int maxlength = 0;
    vector<int> h(n);
    int left = 0;
    int right = 0;
    for (int i = 0; i < n; i++){
        fin >> h[i];
    }
    for (int i = 0; i < n; i++){
        right = i;
        while (h[right] - h[left] >= w){
            left++;
        }
        current = right-left+1;
        if (current > maxlength){
            maxlength = current;
        }
    }
    fout << maxlength;
 
}
