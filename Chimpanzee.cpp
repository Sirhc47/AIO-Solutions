#include <fstream>
#include <iostream> 
using namespace std;
int main(){
    int x,y;
    ifstream input("chimpin.txt");
    ofstream output("chimpout.txt");
    input >> x >> y;
    int square = max(abs(x), abs(y))*2+1;
    int br = square*square;
    int bl = square*square-square+1;
    int tl = bl-square+1;
    int tr = tl-square+1;
    int ans;
    if (x == max(abs(x), abs(y)) && y != -1 * max(abs(x), abs(y)))
    {
        ans = tr - (max(abs(x), abs(y))-y);
        cout << "tr";
    }
    else if (-1 * x == max(abs(x), abs(y))){
        ans = bl - abs(max(abs(x), abs(y))+y);
        cout << "bl";
    }
    else if (-1*y == max(abs(x), abs(y))){
        ans = br - (max(abs(x), abs(y)) - x);
        cout << "br";
    }
    else{
        ans = tl - abs(max(abs(x), abs(y)) + x);
        cout << "tl";
    }
    output << ans -1;
    cout << ans -1;
}
