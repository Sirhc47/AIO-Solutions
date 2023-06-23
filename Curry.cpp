#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace::std;
int main(){
    ifstream input("curryin.txt");
    ofstream output("curryout.txt");
    int n = 0.5;
    int x = 0;
    int y = 0;
    int z = 0;
    int diff = 0;
    int c,r,v = 0;
    input >> c >> r >> v;
    int big = max(c,max(r,v));
    if (c+r+v>2*max(c,max(r,v))){
        cout << "subtracting\n";
        if (c==big){
            diff = ceil(float(r+v-c)/2);
            x += diff;
            r-= diff;
            v-= diff;
        }
        else if(r==big){
            diff=ceil(float(c+v-r)/2);
            y+=diff;
            c-=diff;
            v-=diff;
 
 
        }
        else if(v==big){
            diff=ceil(float(c+r-v)/2);
            cout << float(c+r-v)/2 << "\n";
            z+=diff;
            c-=diff;
            r-=diff;
        }
    }
    cout << c << " " << r << " " << v << "\n";
    cout << x << " " << y << " " << z << "\n";
 
    if (v >= r+c){
        cout << "v\n";
        x+=r;
        y+=c;
    }
    else if (r >= v + c){
        cout << "r\n";
        x+=v;
        z+=c;
 
    }
    else if (c >= r + v){
        cout << "c\n";
        z+=r;
        y+=v;
 
    }   
 
    output << x << " " << y << " " << z;
 
 
}
