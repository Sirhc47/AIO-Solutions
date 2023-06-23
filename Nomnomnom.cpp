#include <iostream>
#include <fstream>
using namespace std;
int main(){
    int n;
    ifstream fin("nomin.txt");
    ofstream fout("nomout.txt");
    fin >> n;
    int target;
    int ans = 0;
    fin >> target;
    ans++;
    int cur = 0;
    int x;
    for (int i = 0; i < n-1; i++){
        fin >> x;
        cur += x;
        if (cur >= target){
            target = cur;
            ans++;
            cur = 0;
        }
    }
    fout << ans;
}
