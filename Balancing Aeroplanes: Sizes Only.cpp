#include <bits/stdc++.h>
using namespace std;
 
int main() {
    // Put your code here
    freopen("balin.txt", "r", stdin);
    freopen("balout.txt", "w", stdout);
    int n; cin >> n;
    vector<int> v(n);
    int total = 0;
    for (int i = 0;  i< n; i++){
        cin >> v[i];
        total += v[i];
    }
    vector<int> dp(60005, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++){
        for (int j = 60003; j >= v[i]; j--){
            if (dp[j] == 0){
                int x = j-v[i];
                dp[j] = dp[x];
            }
        }
    }
    for (int i = total/2+1; i--; i >= 0){
        if (dp[i]){
            cout << i << " " << total - i;
            return 0;
        }
    }
    
}
