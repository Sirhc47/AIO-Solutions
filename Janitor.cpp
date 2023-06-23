#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace ::std;
bool isHigh(int a, int b, int r, int c, int **matrix) {
    if (a != 0) {
        if (matrix[a - 1][b] > matrix[a][b]) {
            return false;
        }
    }
    if (a != r - 1) {
        if (matrix[a + 1][b] > matrix[a][b]) {
            return false;
        }
    }
    if (b != 0) {
        if (matrix[a][b-1] > matrix[a][b]) {
            return false;
        }
    }
    if (b != c - 1) {
        if (matrix[a][b + 1] > matrix[a][b]) {
            return false;
        }
    }
    return true;
}
int main()
{
    ifstream input("janitorin.txt");
    ofstream output("janitorout.txt");
    int r = 0;
    int c = 0;
    int q = 0;
    input >> r >> c >> q;
    int** floor = new int* [r];
    bool** low = new bool* [r];
    int count = r * c;
    for (int i = 0; i < r; i++) {
        floor[i] = new int[c];
        low[i] = new bool[c];
    }
    for (int j = 0; j < r; j++) {
        for (int k = 0; k < c; k++) {
            low[j][k] = 0;
        }
    }
    int x;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            input >> x;
            floor[i][j] = x;
            if (j != 0) {
                if (floor[i][j - 1] < x) {
                    if (low[i][j - 1] == false) {
                        count--;
                    }
                    low[i][j - 1] = true;
                }
                else{
                    low[i][j] = true;
                    count--;
                }
            }
            if (i != 0) {
                if (floor[i - 1][j] < x) {
                    if (low[i - 1][j] == false) {
                        count--;
                    }
                    low[i - 1][j] = true;
                }
                else if (low[i][j] == false){
                    low[i][j] = true;
                    count--;
                    
                }
            }
        }
    }
    vector<int> ans (q+1,0);
    ans[0] = count;
    int y;
    int z;
    for (int i = 0; i < q; i++) {
        input >> x >> y >> z;
        x--;
        y--;
        //This part is sus
        if (low[x][y] == false) {
            count--;
        }
        floor[x][y] = z;
        if (isHigh(x, y, r, c, floor)) {
            count++;
            low[x][y] = false;
        }
        else {
            low[x][y] = true;          
        }
        //Up to here
        if (x != 0) {
            if (isHigh(x - 1, y, r, c, floor)) {
                if (low[x - 1][y] == true) {
                    count++;
                    low[x - 1][y] = false;
                }
            }
            else if (low[x - 1][y] == false) {
                count--;
                low[x - 1][y] = true;
            }
        }
        if (x != r - 1) {
            if (isHigh(x + 1, y, r, c, floor)) {
                if (low[x + 1][y] == true) {
                    count++;
                    low[x + 1][y] = false;
                }
            }
            else if (low[x + 1][y] == false) {
                count--;
                low[x + 1][y] = true;
            }
        }
        if (y != 0) {
            if (isHigh(x, y - 1, r, c, floor)) {
                if (low[x][y - 1] == true) {
                    count++;
                    low[x][y - 1] = false;
                }
            }
            else if (low[x][y-1] == false) {
                count--;
                low[x][y-1] = true;
            }
        }
        if (y != c - 1) {
            if (isHigh(x, y + 1, r, c, floor)) {
                if (low[x][y + 1] == true) {
                    count++;
                    low[x][y + 1] = false;
                }
            }
            else if (low[x][y+1] == false) {
                count--;
                low[x][y+1] = true;
            }
        }
        ans[i + 1] = count;
    }
    for (int i = 0; i <= q; i++) {
        output << ans[i] << "\n";
    }
}
