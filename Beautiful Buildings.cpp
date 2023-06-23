#include <iostream>
#include <fstream>
using namespace::std;
int main()
{
	int n;
	int h[100000] = {};
	int beauty[100000] = {};
	int maxbeauty = 0;
	int ugliness = 0;
	ifstream input("buildin.txt");
	ofstream output("buildout.txt");
	input >> n;
	for (int i = 0; i < n; i++) {
		input >> h[i];
	}
	beauty[0] = abs(h[1] - h[0]);
	beauty[n - 1] = abs(h[n - 1] - h[n - 2]);
	for (int a = 1; a < n-1; a++) {
		if (h[a - 1] <= h[a] and h[a + 1] >= h[a] or h[a - 1] >= h[a] and h[a + 1] <= h[a]) {
			beauty[a] = 0;
		}
		else {
			beauty[a] = 2*min(abs(h[a - 1] - h[a]), abs(h[a + 1] - h[a]));
		}	
	}
	for (int x = 0; x < n-1; x++) {
		ugliness += abs(h[x] - h[x + 1]);
	}
	for (int y = 0; y < n; y++) {
		cout << beauty[y] << "\n";
		if (beauty[y] > maxbeauty) {
			maxbeauty = beauty[y];
		}
	}
	int ans = ugliness - maxbeauty;
	output << ans;
	output.close();
	input.close();
	return 0;
}
