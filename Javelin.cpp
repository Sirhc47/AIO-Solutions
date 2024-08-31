#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    ifstream fin("javelin.txt");
    ofstream fout("javelout.txt");
    int n;
    fin >> n;
    vector<int> d(n);
    int ans = 0;
    int most = 0;
    for (int i = 0; i < n; i++){
        fin >> d[i];
        if (d[i] > most){
            ans++;
            most = d[i];
        }
    }
    fout << ans;
    
    return 0;
}
