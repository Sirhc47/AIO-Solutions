#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    vector<int> pfx;
    pfx.push_back(0);
    for (int i = 0; i < n; i++){
        cin >> v[i];
        pfx.push_back(v[i]+pfx[i]);
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> leasts;
    for (int i = 0; i <= n; i++){
        pq.push({pfx[i], i});
        while (pq.top().second <= i-k){
            pq.pop();
        }
        leasts.push_back(pq.top().first);
    }
    int ans = -1e9;
    for (int i = 1; i <= n; i++){
        ans = max(ans, pfx[i] - leasts[i-1]);
    }
    cout << ans;
    //cout << ans;
}
