#include <iostream>
#include <fstream>
#include <map>
#include <set>
using namespace::std;
pair<int, int> common(multiset<int> thing){
    int maxcount = 0;
    int count = 0;
    int n;
    for (auto c : thing){
        count = thing.count(c);
        if (count > maxcount){
            maxcount = count;
            n = c;
        }
        
    }
    return make_pair(maxcount, n);
}
int main(){
    int n, s, e, w;
    ifstream input("mousein.txt");
    ofstream output("mouseout.txt");
    int x;
    int y;
    multiset<int> xcount;
    multiset<int> ycount;
    int north = 0;
    int south = 99999999;
    int east = 0;
    int west = 99999999;
 
 
    for (int i = 0; i < 8; i++){
        input >> x;
        input >> y;
        if (x > east){
            east = x;
        }
        if (x < west){
            west = x;
        }
        if (y > north){
            north = y;
        }
        if (y < south){
            south = y;
        }
        xcount.insert(x);
        ycount.insert(y);
 
        
    }
    int side;
    if (common(xcount).first == 4)
    {
        side = common(xcount).second;
        cout << "x " << side;
        if (side == west)
        {
            output << "W";
        }
        else
        {
            output << "E";
        }
    }
    else
    {
        side = common(ycount).second;
        cout << "y " << side;
        if (side == north)
        {
            output << "N";
        }
        else
        {
            output << "S";
        }
    }
}
