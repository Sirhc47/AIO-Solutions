#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream input("handin.txt");
    ofstream output("handout.txt");
    int n;
    int s;
    int k;
    input >> n >> s >> k;
    int a, b;
    for (int i = 0; i < k; i++){
        input >> a >> b;
        if (a < s && b >= s){
            s--;
        }
        else if (a > s && b <= s){
            s++;
        }
        else if (a == s){
            s = b;
        }
        cout << s << "\n";
 
    }
    output << s;
}
