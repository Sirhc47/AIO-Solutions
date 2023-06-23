#include <fstream>
using namespace std;
int main(){
    int n;
    ifstream fin("fashin.txt");
    ofstream fout("fashout.txt");
    fin >> n;
    int ans = 0;
    while (n >= 100){
        n-= 100;
        ans++;
    }
    while (n >= 20)
    {
        n -= 20;
        ans++;
    }
    while (n >= 5)
    {
        n -= 5;
        ans++;
    }
    while (n >= 1)
    {
        n -= 1;
        ans++;
    }
    fout << ans;
}
