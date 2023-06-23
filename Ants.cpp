#include <fstream>
using namespace std;
int main(){
    int n;
    ifstream input("antsin.txt");
    ofstream output("antsout.txt");
    input >> n;
    int ans = 0;
    int previous = -1;
    int streaklength = 0;
    int x;
    for (int i = 0; i < n; i++){
        input >> x;
        if (x > previous){
            streaklength++;
            previous = x;
        }
        else{
            if (streaklength >= 2){
                ans++;
            }
            streaklength = 1;
            previous = x;
        }
 
    }
    if (streaklength >= 2)
    {
        ans++;
    }
    output << ans;
}
