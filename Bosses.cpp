#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
 
using namespace std;
 
typedef int ll;
 
 
 
int salaries[10000];
 
vector<vector<int>> children;
 
//O(N)
 
int calculateSalaries(ll &node){
 
    //if leaf node set salary to 1
 
    if (children[node].size() == 0){
 
        salaries[node] = 1;
 
        return 1;
 
    }
 
    if (salaries[node] != -1){
 
        return salaries[node];
 
    }
 
    //calculate childrens salaries
 
    ll totalchildrensal = 0;
 
    for (auto x : children[node]){
 
        totalchildrensal += calculateSalaries(x);
 
    } 
 
    salaries[node] = 1 + totalchildrensal;
 
    return salaries[node];
 
}
 
signed main(){
 
    ios::sync_with_stdio(false);
 
    cin.tie(0);
 
    ll n;
 
    cin >> n;
 
    vector<vector<ll>> canlead(n);
 
    for (int i = 0; i < n; i++){
 
        ll k; cin >> k;
 
        for (int j = 0; j < k; j++){
 
            ll x; cin >> x;
 
            x--;
 
            canlead[x].push_back(i);
 
        }
 
    }
 
    //try each person as the head of the tree and greedily add people who can be lead
 
    ll ans = 1e17;
 
    //O(n)
 
    for (int i = 0; i < n; i++){
 
        ll cost = 0;
 
        queue<ll> q;
 
        vector<ll> seen(n,0);
 
        seen[i] = 1;
 
        q.push(i);
 
        children.clear();
 
        for (int j = 0; j < n; j++){
 
            vector<int> v;
 
            children.push_back(v);
 
        }
 
        //O(n+k)
 
        while (!q.empty()){
 
            ll u = q.front();
 
            q.pop();
 
            for (auto subordinate : canlead[u]){
 
                if (!seen[subordinate]){
 
                    seen[subordinate] = true;
 
                    q.push(subordinate);
 
                    children[u].push_back(subordinate);
 
                }
 
            }
 
        }
 
        bool flag = false;
 
        for (int j = 0; j < n; j++){
 
            if (!seen[j]){
 
                flag = true;
 
            }
 
        }
 
        if (flag){
 
            continue;
 
        }
 
        for (int j = 0; j < n; j++){
 
            salaries[j] = -1;
 
        }
 
        //O(n)
 
        calculateSalaries(i);
 
        for (int j = 0; j < n; j++){
 
            cost += salaries[j];
 
        }
 
        ans = min(cost,ans);
 
    }
 
    //assert(ans != 1e17);
 
    cout << ans;
 
 
}
