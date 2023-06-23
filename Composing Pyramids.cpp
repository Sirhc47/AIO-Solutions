#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main() {
	int n;
	int p[100000] = { };
	int l[100000] = {};
	int r[100000] = {};
	int lw[100000] = {};
	int rw[100000] = {};
	ifstream input("compin.txt");
	ofstream output("compout.txt");
	input >> n;
	for (int i = 0; i < n; i++) {
		input >> p[i];
	}
	int next = 1;
	l[0] = 1;
	lw[p[0]] = 1;
 
	for (int i = 1; i < n; i++) {
		l[i] = lw[p[i] - 1] + 1;
		lw[p[i]] = l[i];
	}
	r[n-1] = 1;
	rw[p[n-1]] = 1;
	for (int i = n-2; i >= 0; i--) {
		r[i] = rw[p[i] - 1] + 1;
		rw[p[i]] = r[i];
	}
	int length;
	int maxlength = 0;
	for (int a = 0; a < n; a++) {
		length = min(l[a], r[a]);
		if (length > maxlength) {
			maxlength = length;
		}
	}
	int ans = n - maxlength - maxlength + 1;
	output << ans;
	output.close();
	input.close();
	return 0;
}
