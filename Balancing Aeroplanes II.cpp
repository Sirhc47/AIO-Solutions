#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace ::std;
int main()
{
    int n;
    ifstream input("balancein.txt");
    ofstream output("balanceout.txt");
    input >> n;
    vector<int> plots(n);
    for (int i = 0; i < n; i++)
    {
        input >> plots[i];
    }
    int left = 0;
    int right = n - 1;
    int leftsum = 0;
    int rightsum = 0;
    int count = 0;
    while (left < right)
    {
        leftsum += plots[left];
        rightsum += plots[right];
        while (leftsum != rightsum && left < right)
        {
            if (leftsum < rightsum)
            {
                left++;
                leftsum += plots[left];
                count++;
            }
            else
            {
                right--;
                rightsum += plots[right];
                count++;
            }
        }
        left++;
        right--;
        leftsum = 0;
        rightsum = 0;
    }
    output << count;
}
