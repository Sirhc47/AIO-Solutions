#include <fstream>
using namespace std;
int main(){
    int n;
    ifstream input("dishin.txt");
    ofstream output("dishout.txt");
    input >> n;
    int sum = 0;
    int min = 10000;
    int max = 0;
    int x;
    while (input >> x){
        sum += x;
        if (x < min){
            min = x;
        }
        if (x > max){
            max = x;
        }
    }
    output << min << " " << max << " " << sum/n;
