#include<fstream>
#include <iostream>
#include <algorithm>
using namespace::std;
int main()
{
    ifstream input("rpsin.txt");
    ofstream output("rpsout.txt");
    int n;
    int ra;
    int pa;
    int sa;
    int rb;
    int pb;
    int sb;
    input >> n >> ra >> pa >> sa >> rb >> pb >> sb;
    int score = 0;
    int x = min(rb, sa);
    score += x;
    rb -= x;
    sa -= x;
    x = min(pb, ra);
    score += x;
    pb -= x;
    ra -= x;
    x = min(sb, pa);
    score += x;
    sb -= x;
    pa -= x;
    x = min(rb, ra);
    rb -= x;
    ra -= x;
    x = min(pb, pa);
    pb -= x;
    pa -= x;
    x = min(sb, sa);
    sb -= x;
    sa -= x;
    score -= sb;
    score -= rb;
    score -= pb;
    output << score;
 
}
