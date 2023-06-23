#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream fin("snapin.txt");
    ofstream fout("snapout.txt");
    int r, c;
    fin >> r >> c;
    int x1, y1, x2, y2;
    fin >> y1 >> x1 >> y2 >> x2;
    if ((abs(y1-y2)+abs(x1-x2))%2==1){
        fout << "ROSE";
    }
    else{
        fout << "SCARLET";
    }
 
}
