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
#define speed() \
    ios::sync_with_stdio(false); \
    cin.tie(0)
#define file(name) \
    speed(); \
    freopen(#name "in.txt", "r", stdin); \
    freopen(#name "out.txt", "w", stdout)
#define dbg(x) cout << '>' << #x << ':' << x << endl;
#define ll long long
using namespace std;
int main() {
    file(deal);
    int n, m; cin >> n >> m;
    vector<int> v(m), p(m);
    vector<vector<int>> amogus(n+1);
    multiset<pair<int,int>> cheapest;
    vector<int> vent(n+1, 0);
    for (int i = 0; i < m; i++){
        cin >> v[i];
        vent[v[i]]++;
    }
    for (int i = 0; i < m; i++){
        cin >> p[i];
        amogus[v[i]].push_back(p[i]);
        if (v[i] != 1){
            cheapest.insert({p[i], v[i]});
        }
    }
    multiset<pair<int,int>> leaderboard;
    for (int i = 1; i <= n; i++){
        if (i != 1){
            leaderboard.insert({amogus[i].size(), i});
        }
        vector<int> temp = amogus[i];
        sort(temp.begin(), temp.end());
        amogus[i] = temp;
    }
    vector<int> ind(n+1, 0);
    int forvotes = amogus[1].size();
    int sus = 0;
    ll cost = 0;
    
    while (true){
        int leadingvotes = (*leaderboard.rbegin()).first;
        if (leadingvotes < forvotes){
            break;
        }
        int neededvotes = leadingvotes - forvotes + 1;
        int leaders = 0;
        int it = 0;
        ll lowerleadprice = 0;
        auto imposter = leaderboard.rbegin();
        while (true){
            if (imposter == leaderboard.rend()){
                break;
            }
            if ((*imposter).first == leadingvotes){
                lowerleadprice += amogus[(*imposter).second][ind[(*imposter).second]];
                leaders++;
                it++;
                imposter++;

            }
            else{
                break;
            }
        }
        int gapgainbyloweringlead = leaders+1;
        if (gapgainbyloweringlead > neededvotes){
            //buy the cheapest votes
            auto sus = cheapest.begin();
            for (int i = 0; i < neededvotes; i++, sus++){
                cost += (*sus).first;
            }
            break;
        }
        ll altprice = 0;
        auto sus = cheapest.begin();
        for (int i = 0; i < gapgainbyloweringlead; i++, sus++){
            altprice+= (*sus).first;
        }
        if (altprice < lowerleadprice){
            cost += altprice;
            forvotes+=gapgainbyloweringlead;
            auto sus = cheapest.begin();
            for (int i = 0; i < gapgainbyloweringlead; i++){
                ind[(*sus).second]++;
                auto imposter = leaderboard.find({vent[(*sus).second],(*sus).second});
                pair<int, int> crew = *imposter;
                vent[(*sus).second]--;
                leaderboard.erase(imposter);
                leaderboard.insert({crew.first-1, crew.second});
                sus = cheapest.erase(sus);
                //todo: lower leaderboard value for that candidate. Just find it, erase, then insert with lower value
            }
            

        }
        else{
            forvotes+=leaders;
            cost += lowerleadprice;
            //remove used votes
            auto imposter = leaderboard.rbegin();
            for (int i = 0; i < leaders; i++){
                auto sus = cheapest.find({amogus[(*imposter).second][ind[(*imposter).second]], (*imposter).second});
                cheapest.erase(sus);
                pair<int, int> crew = (*imposter);
                vent[crew.second]--;
                auto impos = leaderboard.find(crew);
                leaderboard.erase(impos);
                leaderboard.insert({crew.first-1, crew.second});
                ind[crew.second]++;
            }
        }

    }
    std::cout << cost << "\n";
    return 0;
}
