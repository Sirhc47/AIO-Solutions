#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    freopen("rainin.txt", "r", stdin);
    freopen("rainout.txt", "w", stdout);
    int n, c;
    cin >> n >> c;
    int day = 0;
    int x;
    int sum = 0;
    while (sum < c){
        day++;
        cin >> x;
        sum += x;
    }
    cout << day;
 
}
