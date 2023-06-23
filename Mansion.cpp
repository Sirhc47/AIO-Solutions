#include <fstream>
#include <vector>
using namespace std;
int main(){
    ifstream in("manin.txt");
    ofstream out("manout.txt");
    int n, w;
    in >> n >> w;
    vector<int> houses(n);
    int sum = 0;
    int maxsum = 0;
    for (int i = 0; i < n; i++){
        in >> houses[i];
        sum += houses[i];
        if (i >= w){
            sum-=houses[i-w];
        }
        if (sum > maxsum){
            maxsum = sum;
        }
    }
    out << maxsum;
}
