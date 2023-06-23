#include <fstream>
#include <iostream>
using namespace std;
int main(){
    ifstream input("bendin.txt");
    ofstream output("bendout.txt");
    int x1, y1, x2, y2;
    input >> x1 >> y1 >> x2 >> y2;
    int l1, w1, l2, w2;
    input >> l1 >> w1 >> l2 >> w2;
    int area = (x2-x1)*(y2-y1);
    area += (l2-l1)*(w2-w1);
    int side1 = min(x2, l2)- max(x1, l1);
    int side2 = min(y2, w2) - max(y1, w1);
    int subtract = 0;
    if (side1 > 0 && side2 > 0){
        subtract = side1*side2;
    }
    output << area - subtract;
}
