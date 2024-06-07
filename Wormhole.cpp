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

int main()
{
    //file(worm);
    int r, c, q; cin >> r >> c >> q;
    vector<vector<int>> grid(r, vector<int>(c));
    vector<int> columnsums(c);
    vector<int> rowsums(r);
    for (int i = 0; i < r; i++){
        ll sum = 0;
        for (int j = 0; j < c; j++){
            char temp;
            cin >> temp;
            if (temp == 'B'){
                grid[i][j] = 1;
            }
            else{
                grid[i][j] = 0;
            }
            sum += grid[i][j];
        }
        rowsums[i] = sum;
    }
    for (int i = 0; i < c; i++){
        ll sum = 0;
        for (int j = 0; j < r; j++){
            sum += grid[j][i];
        }
        columnsums[i] = sum;
    }
    //requirement to be solvable: needs either every row to have sum not 0 or not c and at least one column to have sum not 0 or not r or vice versa
    //otherwise the minimum number of modifications to make solvable is 
    bool rowAllDiff = true;
    bool colAllDiff = true;
    bool rowHasDiff = false;
    bool colHasDiff = false;
    int rowneed = 0;
    int colneed = 0;
    if (r == 1){
        //we only care about if row all diff is true
        colHasDiff = true;
    }
    if (c == 1){
        //we only care about if col all diff is true
        rowHasDiff = true;
    }
    for (int i = 0; i < r; i++){
        if (rowsums[i] == 0 || rowsums[i] == c){
            rowAllDiff = false;
            rowneed++;
        }
        else{
            rowHasDiff = true;
        }
    }
    for (int i = 0; i < c; i++){
        if (columnsums[i] == 0 || columnsums[i] == r){
            colAllDiff = false;
            colneed++;
        }
        else{
            colHasDiff = true;
        }
    }
    if (r == 1 && c == 1){
        cout << 0 << "\n";
    }
    else if ((rowAllDiff && colHasDiff) || (colAllDiff && rowHasDiff)){
        cout << 0 << "\n";
    }
    else{


        //if there is only one row or column that is completely different it takes two moves
        /* ie
            0000
            0000
            1111
            0000
            1111
        
         */
        if (r == 1 || c == 1)
        {
            cout << 1 << "\n";
        }
        else if ((rowHasDiff == false && (columnsums[0] == 1 || columnsums[0] == r-1)) || (colHasDiff == false && (rowsums[0] == 1 || rowsums[0] == c-1))){
            cout << 2 << "\n";
        }
        else if (rowHasDiff != colHasDiff)
        {
            cout << 1 << "\n";
        }
        else{
            cout << min(rowneed,colneed) << "\n";
        }

    }
    while (q--){
        if (r == 1 && c == 1){
            cout << 0 << "\n";
            continue;
        }
        int x,y; cin >> x >> y;
        x--; y--;
        grid[x][y] = 1 - grid[x][y];
        if (grid[x][y] == 0){
            rowsums[x]--;
            columnsums[y]--;
        }
        else{
            rowsums[x]++;
            columnsums[y]++;
        }
        rowAllDiff = true;
        colAllDiff = true;
        rowHasDiff = false;
        colHasDiff = false;
        rowneed = 0;
        colneed = 0;
        if (r == 1)
        {
            // we only care about if row all diff is true
            colHasDiff = true;
        }
        if (c == 1)
        {
            // we only care about if col all diff is true
            rowHasDiff = true;
        }
        for (int i = 0; i < r; i++)
        {
            if (rowsums[i] == 0 || rowsums[i] == c)
            {
                rowAllDiff = false;
                rowneed++;

            }
            else
            {
                rowHasDiff = true;
            }
        }
        for (int i = 0; i < c; i++)
        {
            if (columnsums[i] == 0 || columnsums[i] == r)
            {
                colAllDiff = false;
                colneed++;
            }
            else
            {
                colHasDiff = true;
            }
        }
        if ((rowAllDiff && colHasDiff) || (colAllDiff && rowHasDiff))
        {
            cout << 0 << "\n";
        }
        else
        {
            if (r == 1 || c == 1){
                cout << 1 << "\n";
            }
            else if ((rowHasDiff == false && (columnsums[0] == 1 || columnsums[0] == r - 1)) || (colHasDiff == false && (rowsums[0] == 1 || rowsums[0] == c - 1)))
            {
                cout << 2 << "\n";
            }
            else if (rowHasDiff != colHasDiff)
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << min(rowneed, colneed) << "\n";
            }

        }
    }
    return 0;
}
