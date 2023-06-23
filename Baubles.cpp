#include <iostream>
#include <fstream>
#include <algorithm>
using namespace::std;
int main()
{
    ifstream input("baublesin.txt");
    ofstream output("baublesout.txt");
    int ro;
    int bo;
    int s;
    int rp;
    int bp;
    input >> ro >> bo >> s >> rp >> bp;
    int ans = 0;
    if (ro > rp && bo > bp) {
        if (rp == 0) {
            ans = bo - bp + 1 + s;
        }
        else if (bp == 0) {
            ans = ro - rp + 1 + s;
        }
        else {
            ans = min(ro - rp, bo - bp) + 1 + s;
        }
        
    }
    else if (ro < rp && bo < bp) {
        ans = s - (rp - ro + bp - bo) + 1;
    }
    else {
        if (bp == 0) {
            ans = s - rp + ro + 1;
        }
        else if (rp == 0) {
            ans = s - bp + bo + 1;
        }
        else {
            ans = s - max(rp - ro, bp - bo) + 1;
        }
    }
 
 
    output << max(ans, 0);
}
