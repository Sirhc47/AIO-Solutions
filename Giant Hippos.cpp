#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    ifstream input("hippoin.txt");
    ofstream output("hippoout.txt");
    int n, h, f;
    int x;
    input >> n >> h >> f;
    vector<int> hippos(h);
    if (h == 1){
        if (f >= 2){
            output << n-1;
            return 0;
        }
        else{
            input >> x;
            output << max(x-1, n-x);
            return 0;
        }
    }
    vector<int> gaps(h - 1);
    for (int i = 0; i < h; i++){
        input >> hippos[i];
        if (i != 0){
            gaps[i-1] = hippos[i]-hippos[i-1]-1;
        }
    }
    int edge1 = hippos[0]-1;
    int edge2 = n-hippos[h-1];
    sort(gaps.rbegin(),gaps.rend());
    if (f == 1){
        output << max(edge1, edge2);
        return 0;
    }
    int bothedge = edge1+edge2;
    for (int i = 0; i < (f-2)/2; i++){
        if (i >= gaps.size()){
            break;
        }
        bothedge += gaps[i];
    }
    int edge = max(edge1, edge2);
    for (int i = 0; i < (f - 1) / 2; i++)
    {
        if (i >= gaps.size())
        {
            break;
        }
            edge += gaps[i];
    }
    int noedge = 0;
    for (int i = 0; i < f / 2; i++)
    {
        if (i >= gaps.size())
        {
            break;
        }
            noedge += gaps[i];
    }
    output << max(edge, max(noedge, bothedge));
}
