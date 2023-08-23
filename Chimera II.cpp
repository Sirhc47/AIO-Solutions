#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace::std;
int main(){
    ifstream input("chimin.txt");
    ofstream output("chimout.txt");
    int n;
    int splices = 0;
    bool possible = true;
    int current = 3; //1 for a, 2 for b, 3 for both
    input >> n;
    cout << n << "\n";
    vector<char> a(n);
    vector<char> b(n);
    vector<char> c(n);
    for (int i = 0; i < n; i++){
        input >> a[i];
    }
    for (int i = 0; i < n; i++){
        input >> b[i];
    }
    for (int i = 0; i < n; i++){
        input >> c[i];
    }
    for (int i = 0; i < n; i++){
        if (current == 1){
            if (a[i] == c[i]){
                current == 1;
            }
            else if (b[i] == c[i]){
                current = 2;
                splices++;
            }
            else{
                possible = false;
                break;
            }
        }
        if (current == 2){
            if (b[i] == c[i]){
                current = 2;
            }
            else if (a[i] == c[i]){
                current = 1;
                splices++;
            }
            else{
                possible = false;
                break;
            }
 
        }
        if (current == 3){
            if (a[i] == c[i] && b[i] == c[i]){
                current == 3;
            }
            else if (a[i] == c[i]){
                current = 1;
            }
            else if (b[i] == c[i]){
                current = 2;
            }
            else{
                possible = false;
                break;
            }
 
        }
        cout << current << "\n";
    }
    if (possible == false){
        output << "PLAN FOILED";
    }
    else{
        output << "SUCCESS\n" << splices;
    }
 
 
}
