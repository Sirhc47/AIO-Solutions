#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace::std;
int end(int start, int length, int size, string snak, char first) {
    int chain = 0;
    int c = -1;
    for (int i = start; i < size; i++) {
        if (snak[i] == first) {
            chain++;
            if (chain == length) {
                return i;
            }
        }
        
    }
    return -1;
 
}
 
 
bool owo(int length, int size, string snak) {
    int a = end(0, length, size, snak, 'S');
    if (a < 0) {
        return false;
    }
    int b = end(a, length, size, snak, 'N');
    if (b < 0) {
        return false;
    }
    int c = end(b, length, size, snak, 'A');
    if (c < 0) {
        return false;
    }
    int d = end(c, length, size, snak, 'K');
    if (d < 0) {
        return false;
    }
    int e = 0;
    for (int i = d; i < size; i++) {//Can have a vector with ecount
        if (snak[i] == 'E') {
            e++;
            if (e == length) {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    ifstream input("snakein.txt");
    ofstream output("snakeout.txt");
    string snake;
    int useless;
    input >> useless;
    input >> snake;
    int uwu = 0;
 
    for (auto c : snake) {
        if (c == 'S') {
            uwu++;
        }
    }
    int low = 1;
    int mid;
    int works = 0;
    while (low <= uwu) {
        mid = (low + uwu) / 2;
 
        cout << low << " " << mid << " " << uwu << "\n";
        if (owo(mid, useless, snake)) {
            works = mid;
            low = mid+1;
            cout << " pass";
        }
        else {
            uwu = mid - 1;
        }
        cout << "\n";
        
    }
    output << works;
    input.close();
    output.close();
    return 0;
}
