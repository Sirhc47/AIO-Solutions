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
#define dbg(x) cout << '>' << #x << ':' << x << endl;
using namespace std;
int main()
{
    file(snap);
    int n;
    cin >> n;
    vector<pair<int, int>> locs(n + 1);
    vector<int> count(n+1);
    vector<int> cards(2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> cards[i];
        count[cards[i]]++;
        if (count[cards[i]] == 1){
            locs[cards[i]].first = i;
        }
        if (count[cards[i]] == 2){
            locs[cards[i]].second = i;
        }
    }
    int snap = 0;
    int firstcard = cards[0];
    int secondcard = cards[1];
    int p = 1;
    int prev = -1;
    while (p <= cards.size()){ 
        secondcard = cards[p];
/*         cout << firstcard << " " << secondcard << " ";
        for (int i = p+1; i < cards.size(); i++){
            cout << cards[i] << " ";
        }
        cout << "\n"; */
        if (firstcard == prev){
            snap++;
            prev = firstcard;
            firstcard = secondcard;
            p++;
            count[prev]--;
            continue;
        }
        if (secondcard == prev){
            snap++;
            prev = secondcard;
            p++;
            count[prev]--;
            continue;
        }
        if (count[firstcard] < 2){
            prev = firstcard;
            firstcard = secondcard;
            p++;
            count[prev]--;
            continue;
        }
        if (count[secondcard] < 2){
            prev = secondcard;
            p++;
            count[prev]--;
            continue;
        }
        if (p+1 < cards.size() && cards[p+1] == secondcard){
            prev = secondcard;
            p++;
            count[prev]--;
            continue;
        }
        if (p+1 < cards.size() && cards[p + 1] == firstcard)
        {
            prev = firstcard;
            firstcard = secondcard;
            p++;
            count[prev]--;
            continue;
        }
        if (locs[firstcard].second < locs[secondcard].second){
            prev = secondcard;
            p++;
            count[prev]--;
            continue;
        }
        prev = firstcard;
        firstcard = secondcard;
        p++;
        count[prev]--;
    }
    cout << snap;
}
