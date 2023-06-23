#include <iostream>
#include <fstream>
using namespace std;
int main(){
    int r, s;
    ifstream input("snapin.txt");
    ofstream output("snapout.txt");
    int ra[100005] = {0};
    int sa[100005] = {0};
    input >> r >> s;
    int x;
    for (int i = 0; i < r; i++){
        input >> x;
        ra[x]++;
    }
    long long ans = 0;
    for (int i = 0; i < s; i++){
        input >> x;
        sa[x]++;
    }
    for (int i = 0; i < 100005; i++){
        if (ra[i] != 0 && sa[i] != 0){
            ans += ra[i]*sa[i];
        }
    }
    output << ans;
}
