#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main()
{
    int n;
    int f;
    ifstream input("spacein.txt");
    ofstream output("spaceout.txt");
    input >> n;
    input >> f;
    vector<int> c(n, 0);
    //l is increasing r is decreasing
    vector<int> l;
    vector<int> r;
    vector<int> lh;
    vector<int> rh;
    for (int i = 0; i < n; i++) {
        input >> c[i];
    }
    int minl = f;
    int minr = f;
    for (int i = 0; i < n; i++) {
        if (c[i] < minl) {
            l.push_back(i);
            minl = c[i];
            if (c[i] <= f / 2) {
                lh.push_back(i);
            }
        }
        if (c[n - i - 1] < minr) {
            r.push_back(n - i - 1);
            minr = c[n - i - 1];
            if (c[n - i - 1] <= f / 2) {
                rh.push_back(n - i - 1);
            }
        }
    }
    int lmaxlength = 0;
    int rmaxlength = 0;
    int lpass = r.size();
    int rpass = l.size();
    for (int i = 0; i < lh.size(); i++) {
        for (int j = 0; j < lpass; j++) {
            if (c[r[j]] + c[lh[i]] <= f) {
                cout << "LPass: " << lh[i] << " " << r[j] << " Length: " << r[j] - lh[i] + 1 << "\n";
                if (r[j] - lh[i] + 1 >= lmaxlength) {
                    lmaxlength = r[j] - lh[i] + 1;
                    lpass = j;
                }
                break;
            }
        }
        if (r[0] - lh[i] + 3 < lmaxlength) {
            break;
        }
    }
    for (int i = 0; i < rh.size(); i++) {
        for (int j = 0; j < rpass; j++) {
            if (c[l[j]] + c[rh[i]] <= f) {
                cout << "RPass: " << l[j] << " " << rh[i] << " Length: " << rh[i] - l[j] + 1 << "\n";
                if (rh[i] - l[j] + 1 >= rmaxlength) {
                    rmaxlength = rh[i] - l[j] + 1;
                    rpass = j;
                }
                break;
            }
        }
        if (rh[i] - l[0] + 3 < rmaxlength) {
            break;
        }
    }
    int ans = -1;
    if (max(lmaxlength, rmaxlength) > 1) {
        ans = max(lmaxlength, rmaxlength);
    }
    output << ans;
    output.close();
    input.close();
    return 0;
 
}
