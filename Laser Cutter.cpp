#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
#include <fstream>
#include <string>
using namespace::std;
 
int ans;
int n;
string sus;
string amogus;
vector<char> a;
vector<char> b;
int main(void) {
	ifstream input("laserin.txt");
	ofstream output("laserout.txt");
	input >> n >> sus >> amogus;
	for (char c : sus) {
		a.push_back(c);
	}
	for (char c : amogus) {
		b.push_back(c);
	}
	vector<int> aheight(n+1, 0);
	vector<int> bheight(n+1, 0);
	int y = n;
	int x = 0;
	for (int i = 0; i < 2*n; i++) {
		if (a[i] == 'D') {
			y--;
		}
		if (a[i] == 'R') {
			aheight[x] = y;
			x++;
		}
	}
	y = n;
	x = 0;
	for (int i = 0; i < 2*n; i++) {
		if (b[i] == 'D') {
			y--;
		}
		if (b[i] == 'R') {
			bheight[x] = y;
			x++;
		}
	}
	int current = -1;
	int max = 0;
	bool square = true;
	int height = 0;
	for (int i = 0; i < n-max; i++) {
		if (aheight[i] != current) {
			cout << "i: " << i << "\n";
			current = aheight[i];
			height = max;
			//this part needs to faster. test max first then increase by 1
			if (bheight[i + max] <= current) {
				square = false;
			}
			while (square) {
				height++;
				if (bheight[i + height-1] - current < height) {
					square = false;
				}
			}
			square = true;
			if (height-1 > max) {
				max = height-1;
			}
 
		}
	}
	ans = max;
	 /* Write the answer to the output file. */
	output << ans;
	/* Finally, close the input/output files. */
	input.close();
	output.close();
	return 0;
}
