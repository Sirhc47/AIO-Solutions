#include <fstream>
using namespace std;
int main(){
    int n;
    ifstream in("countin.txt");
    ofstream out("countout.txt");
    in >> n;
    for (int i = 1; i <= n; i++){
        out << i << "\n";
    }
}
