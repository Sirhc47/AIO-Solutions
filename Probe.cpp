#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
using namespace ::std;
long long dist(int x1, int y1, int x2, int y2)
{
    long long x = abs(x1-x2);
    long long y = abs(y1-y2);
    return x*x+y*y;
}
int main()
{
    ifstream input("probein.txt");
    ofstream output("probeout.txt");
    int r, c, rp, cp, rf, cf;
    input >> r >> c >> rp >> cp >> rf >> cf;
    int q;
    input >> q;
    int x, y;
    int waterdist;
    int lavadist;
    string out;
    vector<string> ans;
    for (int i = 0; i < q; i++)
    {
        input >> x >> y;
        if (abs(cf - cp) == abs(rf - rp))
        {
            if (dist(x, y, rp, cp) < dist(x, y, rf, cf))
            {
                out = "WATER";
            }
            else if (dist(x, y, rp, cp) > dist(x, y, rf, cf))
            {
                out = "LAVA";
            }
            else
            {
                out = "MOUNTAINS";
            }
        }
        else
        {
            waterdist = abs(x - rp) + abs(y - cp);
            lavadist = abs(x - rf) + abs(y - cf);
            if (waterdist < lavadist)
            {
                out = "WATER";
            }
            else if (waterdist > lavadist)
            {
                out = "LAVA";
            }
            else
            {
                out = "MOUNTAINS";
            }
        }
        ans.push_back(out);
    }
    for (int i = 0; i < ans.size(); i++)
    {
        output << ans[i] << "\n";
    }
}
