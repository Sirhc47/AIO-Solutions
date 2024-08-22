#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <climits>
#include <string>
#include <unordered_map>
#define speed()                  \
    ios::sync_with_stdio(false); \
    cin.tie(0)
#define file(name)                       \
    speed();                             \
    freopen(#name "in.txt", "r", stdin); \
    freopen(#name "out.txt", "w", stdout)
#define dbg(x) cout << '>' << #x << ':' << x << endl;
#define ll long long
using namespace std;
ll gcd(ll a, ll b)
{
    if (b > a)
    {
        return gcd(b, a);
    }
    if (b == 0){
        return a;
    }
    return gcd(b, a % b);
    // LCM = (a*b)/gcd(a,b)
}
int t[2000000];
void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}
int sum(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}
const int dx[5] {1, 0, -1, 0, 0}, dy[5]{0, 1, 0, -1, 0};


int r, c;
void ee(vector<string> grid, vector<vector<int>> toggles)
{
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c;  j++){
            if (grid[i][j] == '.'){
                for (int k = 0; k < r; k++){
                    toggles[k][j] = (toggles[k][j] + 1) % 2;
                }
                for (int k = 0; k < c; k++){
                    toggles[i][k] = (toggles[i][k] + 1) % 2;
                }
                toggles[i][j] = (toggles[i][j]+1)%2;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (toggles[i][j] == 1)
            {
                count++;
            }
        }
    }
    cout << count << "\n";
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (toggles[i][j] == 1){
                cout << i << " " << j << "\n";
            }
        }
    }
}

void oo(vector<string> grid, vector<vector<int>> toggles){
    for (int i = 0; i < r-1; i++){
        for (int j = 0; j < c-1; j++){
            if (grid[i][j] == '.'){
                toggles[i][j] = (toggles[i][j] + 1) % 2;
                toggles[i+1][j] = (toggles[i+1][j] + 1) % 2;
                toggles[i][j+1] = (toggles[i][j+1] + 1) % 2;
                toggles[i+1][j+1] = (toggles[i+1][j+1] + 1) % 2;
                grid[i][j] = '*';
                if (grid[i+1][j] == '.'){
                    grid[i+1][j] = '*';
                }
                else{
                    grid[i+1][j] = '.';
                }
                if (grid[i][j+1] == '.'){
                    grid[i][j+1] = '*';
                }
                else{
                    grid[i][j+1] = '.';
                }
                if (grid[i+1][j+1] == '.'){
                    grid[i+1][j+1] = '*';
                }
                else{
                    grid[i+1][j+1] = '.';
                }

            }
        }
    }
    //check the last row and column
    int on = 0;
    for (int i = 0; i < r; i++){
        if (grid[i][c-1] == '*'){
            on++;
        }
    }
    for (int i = 0; i < c-1; i++){
        if (grid[r-1][i] == '*'){
            on++;
        }
    }
    if (on == 0 || on == r + c - 1){
        //possible
        if (on == 0){
            toggles[r-1][c-1] = 1;
        }
        int count = 0;
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                if (toggles[i][j] == 1){
                    count++;
                }
            }
        }
        cout << count << "\n";
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                if (toggles[i][j] == 1){
                    cout << i << " " << j << "\n";
                }
            }
        }
    }
    else{
        cout << "-1\n";
    }
}

void oe(vector<string> grid, vector<vector<int>> toggles){
    for (int i = 0; i < c; i++){
        for (int j = 0; j < r-1; j++){
            if (grid[j][i] == '.'){
                grid[j][i] = '*';
                if (grid[j+1][i] == '.'){
                    grid[j+1][i] = '*';
                }
                else{
                    grid[j+1][i] = '.';
                }
                for (int k = 0; k < c; k++){
                    if (k!= i){
                        toggles[j][k] = (toggles[j][k] + 1) % 2;
                        toggles[j+1][k] = (toggles[j+1][k] + 1) % 2;
                    }
                }
            }
        }
    }
    int on = 0;
    for (int i = 0; i < c; i++){
        if (grid[r-1][i] == '*'){
            on++;
        }
    }
    if (on == 0 || on == c){
        //possible
        if (on == 0){
            for (int i = 0; i < c-1; i++){
                toggles[r-1][i] = 1 - toggles[r-1][i];
            }
            for (int i = 0; i < r-1; i++){
                toggles[i][c-1] = 1 - toggles[i][c-1];
            }
        }
        int count = 0;
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                if (toggles[i][j] == 1){
                    count++;
                }
            }
        }
        cout << count << "\n";
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                if (toggles[i][j] == 1){
                    cout << i << " " << j << "\n";
                }
            }
        }
    }
    else{
        cout << "-1\n";
    }
    

}


void eo(vector<string> grid, vector<vector<int>> toggles){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c-1; j++){
            if (grid[i][j] == '.'){
                grid[i][j] = '*';
                if (grid[i][j+1] == '.'){
                    grid[i][j+1] = '*';
                }
                else{
                    grid[i][j+1] = '.';
                }
                for (int k = 0; k < r; k++){
                    if (k!= i){
                        toggles[k][j] = (toggles[k][j] + 1) % 2;
                        toggles[k][j+1] = (toggles[k][j+1] + 1) % 2;
                    }
                }
            }
        }
    }
    
    int on = 0;
    for (int i = 0; i < r; i++){
        if (grid[i][c-1] == '*'){
            on++;
        }
    }
    if (on == 0 || on == r){
        //possible
        if (on == 0){
            for (int i = 0; i < r-1; i++){
                toggles[i][c-1] = 1 - toggles[i][c-1];
            }
            for (int i = 0; i < c-1; i++){
                toggles[r-1][i] = 1 - toggles[r-1][i];
            }
        }
        int count = 0;
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                if (toggles[i][j] == 1){
                    count++;
                }
            }
        }
        cout << count << "\n";
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                if (toggles[i][j] == 1){
                    cout << i << " " << j << "\n";
                }
            }
        }
    }
    else{
        cout << "-1\n";
    }
}



int main()
{
    file(yalp);
    cin >> r >> c;
    vector<string> grid(r);
    for (int i = 0; i < r; i++){
        cin >> grid[i];
    }
    vector<vector<int>> toggles(r, vector<int>(c, 0));
    if (r%2 == 0 && c%2 == 0){
        ee(grid, toggles);
        return 0;
    }
    if (r%2 == 1 && c%2 == 1){
        oo(grid, toggles);
        return 0;
        }
    if (r%2 == 0 && c%2 == 1){
        eo(grid, toggles);
        return 0;
    }
    if (r%2 == 1 && c%2 == 0){
        oe(grid, toggles);
        return 0;
    }
    return 0;
}
