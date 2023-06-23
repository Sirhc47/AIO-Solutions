#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#define speed()                  \
    ios::sync_with_stdio(false); \
    cin.tie(0)
#define file(name)                       \
    speed();                             \
    freopen(#name "in.txt", "r", stdin); \
    freopen(#name "out.txt", "w", stdout)
#define dbg(x) cout << '>' << #x << ':' << x << endl;
using namespace std;
int main()
{
    file(chim);
    int n; cin >> n;
    vector<char> lion(n);
    for (int i = 0; i< n; i++){
        cin >> lion[i];
    }
    vector<char> snake(n);
    for (int i = 0; i < n; i++)
    {
        cin >> snake[i];
    }
    vector<char> goat(n);
    for (int i = 0; i < n; i++)
    {
        cin >> goat[i];
    }
    int l = 0;
    int s = 0;
    int g = 0;
    int three = 0;
    int two = 0;
    for (int i = 0; i < n; i++){
        if (lion[i] == snake[i] && snake[i] == goat[i]){
            three++;
            l++;
            s++;
            g++;
            continue;
        }
        if (lion[i] == snake[i]){
            two++;
            l++;
            s++;
            continue;
        }
        if (snake[i] == goat[i]){
            two++;
            s++;
            g++;
            continue;
        }
        if (lion[i] == goat[i]){
            two++;
            l++;
            g++;
            continue;
        }
    }
    int a = min(l, min(g, s));
    int c = max(l, max(g, s));
    int b = l+g+s-a-c;
    int rem = n-three-two;
    if (b-a >= rem){
        a+= rem;
        rem = 0;
        cout << (b+a)/2;
        return 0;
    }
    else{
        rem -= (b-a);
        a = b;
        while (rem >= 2 && b < c){
            rem-=2;
            a++;
            b++;
        }
        if (a == b && b == c){
            while (rem >= 3){
                rem-=3;
                a++;
                b++;
                c++;
            }
            cout << (a+b)/2;
            return 0;
        }
        cout << (a+b)/2;
        return 0;
    }

}
