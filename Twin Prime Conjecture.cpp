#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#define speed()                  \
    ios::sync_with_stdio(false); \
    cin.tie(0)
#define file(name)                       \
    speed();                             \
    freopen(#name "in.txt", "r", stdin); \
    freopen(#name "out.txt", "w", stdout)
using namespace std;
int main()
{
    bool isprime;
    file(prime);
    int n; cin >> n;
    vector<int> primes;
    for (int i = 2; i <= n; i++){
        isprime = true;
        if (i <= 3){
            primes.push_back(i);
            continue;
        }
        if (i%2 == 0 || i%3 == 0){
            continue;
        }
        for (int k = 5; k*k <= i; k+=6){
            if (i%k == 0 || i%(k+2) == 0){
                isprime = false;
                break;
            }
        }
        if (isprime){
            primes.push_back(i);
        }
    }
    for (auto c : primes){
        cout << c << "\n";
    }
}
