#include <iostream>
#include <fstream>
#include <cmath>
using namespace::std;
int main() {
  ifstream input("mixin.txt");
  ofstream output("mixout.txt");
  int n, d;
  input >> n >> d;
  int a = floor(n/d);
  if (n==d*a){
    output << a;
  }
  else{
    output << a << " " << n-d*a << "/" << d;
  }
}
