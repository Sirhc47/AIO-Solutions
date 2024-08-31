#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#define ll long long
//Sirhc47
using namespace std;

int main()
{
    ifstream fin("backin.txt");
    ofstream fout("backout.txt");
    int n, k;
    fin >> n >> k;
    vector<int> dists(n-1);
    for (int i = 0; i < n-1; i++){
        fin >> dists[i];
    }
    vector<int> c(n);
    for (int i = 0; i < n; i++){
        fin >> c[i];
    }
    map<int, int> cnt;

    cnt[c[0]] = k;
    ll ans = 0;
    for (int i = 0; i < n-1; i++){
        ll need = dists[i];
        int cost = 1;
        while (need != 0){
            int use = min(need, 1ll*cnt[cost]);
            ans += use*cost;
            cnt[cost]-=use;
            cost++;
            need-=use;
        }
        int newcost = c[i+1];
        int less = 0;
        for (int i = 1; i < newcost; i++){
            less += cnt[i];
        }
        int newamount = k-less;
        cnt[newcost] = newamount;
        for (int i = newcost+1; i <= 20; i++){
            cnt[i] = 0;
        }
    }
    fout << ans;
    return 0;
}
