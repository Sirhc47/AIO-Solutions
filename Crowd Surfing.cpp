#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
 
using namespace std;
vector<vector<int>> grid;
int countways(int l, int w){
    int count = 1;
    if (l == 0 && w == 0){
        return 1;
    }
    if (l == 0){
        if (grid[l][w-1] == -1){
            count += countways(l, w-1);
        }
        else{
            return 1;
        }
    }
    else if (w == 0){
        if (grid[l-1][w] == 1){
            count += countways(l-1, w);
        }
        else{
            return 1;
        }
    }
    else{
        if (grid[l - 1][w] == 1)
        {
            count += countways(l - 1, w);
        }
        if (grid[l][w - 1] == -1)
        {   
            count += countways(l, w - 1);
        }
    }
    return count;
}
int main()
{
    freopen("surfin.txt", "r", stdin);
    freopen("surfout.txt", "w", stdout);
    int l, w;
    cin >> l >> w;
    char x;
    vector<int> temp;
    for (int i = 0; i < l; i++)
    {
        temp.clear();
        for (int j = 0; j < w; j++)
        {
            cin >> x;
            if (x == 'v')
            {
                temp.push_back(1);
            }
            else if (x == '>')
            {
                temp.push_back(-1);
            }
            else if (x == '*')
            {
                temp.push_back(0);
            }
            if (x == '+')
            {
                temp.push_back(4);
            }
        }
        grid.push_back(temp);
    }
    cout << l*w - countways(l-1,w-1);
 
 
    return 0;
}
