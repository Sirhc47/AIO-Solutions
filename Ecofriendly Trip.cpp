#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define speed()                                                                \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0)
#define file(name)                                                             \
  speed();                                                                     \
  freopen(#name "in.txt", "r", stdin);                                         \
  freopen(#name "out.txt", "w", stdout)
#define dbg(x) cout << '>' << #x << ':' << x << endl;
#define ll long long
using namespace std;
vector<vector<ll>> dp;
vector<vector<ll>> prefix;
ll dpcalc(int x, int y, int k, int n) {
  ll fromabove = -1;
  ll fromleft = -1;
  if (x >= 1) {
    fromabove = dp[x - 1][y];
    if (x + k / 2 <= n - 1) {
      // add bottomright prefix
      fromabove += prefix[x + k / 2][min(y + k / 2, n-1)];
      // subtract bottomleft prefix and topright prefix
      // topright
      fromabove -= prefix[x + k / 2 - 1][min(y + k / 2, n-1)];
      if (y - k / 2 - 1 >= 0) {
        // bottom left
        fromabove -= prefix[x + k / 2][y - k / 2 - 1];
      }
      // add topleft prefix
      if (y - k / 2 - 1 >= 0) {
        fromabove += prefix[x + k / 2 - 1][y - k / 2 - 1];
      }
    }
  }
  if (y >= 1) {
    fromleft = dp[x][y - 1];
    if (y + k / 2 <= n - 1) {
      // add bottomright prefix
      fromleft += prefix[min(x + k / 2, n-1)][y + k / 2];
      // subtract bottomleft prefix and topright prefix
      // bottomleft
      fromleft -= prefix[min(x + k / 2, n-1)][y + k / 2 - 1];
      if (x - k / 2 - 1 >= 0) {
        // topright
        fromleft -= prefix[x - k / 2 - 1][y + k / 2];
      }
      // add topleft prefix
      if (x - k / 2 - 1 >= 0) {
        fromleft += prefix[x - k / 2 - 1][y + k / 2 - 1];
      }
    }
  }
  if (fromabove == -1) {
    return fromleft;
  }
  if (fromleft == -1) {
    return fromabove;
  }
  return min(fromleft, fromabove);
}
int main() {
  // file(eco);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> grid;
  for (int i = 0; i < n; i++) {
    vector<int> temp;
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      temp.push_back(x);
    }
    grid.push_back(temp);
  }

  for (int i = 0; i < n; i++) {
    vector<ll> temp;
    for (int j = 0; j < n; j++) {
      temp.push_back(0);
    }
    prefix.push_back(temp);
  }
  //cout << "\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      prefix[i][j] = grid[i][j];
      if (i >= 1) {
        prefix[i][j] += prefix[i - 1][j];
      }
      if (j >= 1) {
        prefix[i][j] += prefix[i][j - 1];
      }
      if (i >= 1 && j >= 1) {
        prefix[i][j] -= prefix[i - 1][j - 1];
      }
      //cout << prefix[i][j] << " ";
    }
    //cout << "\n";
  }
  //cout << "\n";
  // dp through the grid

  for (int i = 0; i < n; i++) {
    vector<ll> temp;
    for (int j = 0; j < n; j++) {
      temp.push_back(0);
    }
    dp.push_back(temp);
  }
  dp[0][0] = prefix[(k - 1) / 2][(k - 1) / 2];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i + j != 0) {
        dp[i][j] = dpcalc(i, j, k, n);
      }
      //cout << dp[i][j] << " ";
    }
    //cout << "\n";
  }
  cout << dp[n - 1][n - 1];
}
