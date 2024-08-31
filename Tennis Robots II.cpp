#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <climits>
#include <string>
#include <unordered_map>
#define ll long long
//Sirhc47
using namespace std;

int main()
{
    ifstream fin("tennisin.txt");
    ofstream fout("tennisout.txt");
    int n, m;
    fin >> n >> m;
    vector<int> x(n);
    for (int i = 0; i < n; i++){
        fin >> x[i];
    }
    vector<int> change(n, 0);
    vector<int> low(n, 0);
    vector<pair<int,int>> steps(m);
    for (int i = 0; i < m; i++){
        int a, b;
        fin >> a >> b;
        a--;
        b--;
        steps[i] = {a,b};
        change[a]--;
        change[b]++;
        low[a] = min(low[a], change[a]);
    }

    vector<int> newx(n);
    bool flag = false;
    for (int i = 0; i < n; i++){
        newx[i] = x[i] + low[i];
        if (newx[i] < 0){
            flag = true;
        }
    }
    if (flag){
        ll ans = 0;
        for (int i = 0; i < m; i++){
            int a = steps[i].first;
            int b = steps[i].second;
            x[a]--;
            x[b]++;
            if (x[a] < 0)
            {
                break;
            }
            ans++;
        }   
        fout << ans;
        return 0;
    }



    // if all change is 0 it runs forever
    bool forever = true;
    for (int i = 0; i < n; i++)
    {
        if (change[i] != 0)
        {
            forever = false;
        }
    }
    if (forever)
    {
        fout << "FOREVER";
        return 0;
    }
    //newx is lowest point per cycle
    int mostcycles=10000000;
    if (flag){
        mostcycles = 0;
    }
    else{
        for (int i = 0; i < n; i++)
        {
            if (change[i] < 0)
            {
                int chng = -change[i];
                mostcycles = min(mostcycles, newx[i] / chng);
            }
        }
        mostcycles++;
    }
    vector<ll> finalx(n);
    for (int i = 0; i < n; i++){
        finalx[i] = x[i] + 1ll*mostcycles*change[i];
    }
    ll ans = 0;
    ans += 1ll*mostcycles*m;
    for (int i = 0; i < m; i++){
        int a = steps[i].first;
        int b = steps[i].second;
        finalx[a]--;
        finalx[b]++;
        if (finalx[a] < 0){
            break;
        }
        ans++;
    }
    fout << ans;
    return 0;
}
