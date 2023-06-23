#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
using namespace::std;
string ans = "";
int x = 0;
int y = 0;
int temp;
void upleft(){
    ans.append("LR");
    y--;
    x++;
}
void upright(){
    ans.append("RL");
    y--;
    x--;
}
void downright(){
    ans.append("RR");
    x=-1*x;
    y=-1*y;
    x++;
    y--;
}
void downleft(){
    ans.append("LL");
    x=-1*x;
    y=-1*y;
    y--;
    x--;
}
void right(){
    ans.append("R");
    temp = y;
    y = x;
    x = -1 * temp;
    y--;
}
void left(){
    ans.append("L");
    temp = y;
    y = -1 * x;
    x = temp;
    y--;
}
void forward(){
    ans.append("RLLR");
    y-=2;
    cout << "forward\n";
}
void back(){
    ans.append("RRRL");
    y = -1 * y;
    y -= 2;
    cout << "back\n";
 
}
int main(){
    ifstream input("snakein.txt");
    ofstream output("snakeout.txt");
    input >> x >> y;
    int repeat;
    if (y == -1 && x == 1){
        downright();
    }
    if (y == -1 && x == -1){
        downleft();
    }
    if (y == -1 && x == 0){
        ans.append("RRR");
        cout << "backone\n";
        y = 0;
        x = 0;
    }
    while (x!=0 || y!=0){
        if (y > 0 && x == y){ //Moving diagonally right
            repeat = x;
            for (int i = 0; i < repeat; i++){
                upright();
            }
        }
        if (y > 0 && x == -1 * y){ //Moving diagonally left
            repeat = y;
            for (int i = 0; i < repeat; i++){
                upleft();
            }
        }
        if (y > 0 && x == y - 1 && x!= 0){
            repeat = x;
            for (int i = 0; i < repeat; i++){
                upright();
            }
        }
        if (y > 0 && x == -1*y+1 && x!= 0){
            repeat = -1*x;
            for (int i = 0; i < repeat; i++){
                upleft();
            }
        }
        if (x == 0 && y > 0){ //Moving forwards
            while (y >= 2){
                forward();
            }
            if (y == 1){
                y = 0;
                ans.append("RLL");
                cout << "one\n";
            }
        }
        if (y > 1 && y > abs(x)){
            while (y-abs(x)>=2){
                forward();
            }
 
        }
        if (x > 0 && x > y){
            right();
        }
        if (x < 0 && abs(x) > y){
            left();
        }
        if (x == 0 && y <= -2){
            back();
        }
        if (x== 0 && y == -1){
            ans.append("RRR");
            x = 0;
            y = 0;
            cout << "backone\n";
        }
        if (x == 0 && y == 1){
            ans.append("RLL");
            x = 0;
            y = 0;
            cout << "one\n";
        }
        cout << x << " " << y << "\n";
    }
 
 
    output << ans;
 
    
 
}
