#include <fstream>
using namespace std;
int main(){
    ifstream input("cutein.txt");
    ofstream output("cuteout.txt");
    int n;
    input >> n;
    int count = 0;
    int digit;
    for (int i = 0; i< n; i++){
        input >> digit;
        if (digit == 0){
            count++;
        }
        else{
            count = 0;
        }
    }
    output << count;
}
