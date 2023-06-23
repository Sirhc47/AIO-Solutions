#include <fstream>
using namespace std;
int main(){
    ifstream input("cultin.txt");
    ofstream output("cultout.txt");
    int n;
    input >> n;
    int time = 0;
    while (n%2 == 0){
        n /= 2;
        time++;
    }
    output << n << " " << time;
}
