#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace ::std;
int main()
{
    ifstream input("artin.txt");
    ofstream output("artout.txt");
    int n;
    input >> n;
    vector<int> t(n);
    vector<int> h(n);
    vector<int> w(n);
    for (int i = 0; i < n; i++)
    {
        input >> t[i] >> w[i] >> h[i];
    }
    //maybe reverse the whole thing around
    reverse(t.begin(), t.end());
    reverse(h.begin(), h.end());
    reverse(w.begin(), w.end());
    vector<pair<int,long long>> height; 
 
    int x = 0;
    long long top = 0;
    vector<int> toremove;
    height.push_back(make_pair(t[0], h[0]));
    long long record = h[0];
    for (int i = 1; i < n; i++){
        top = 0;
        for (int j = height.size()-1; j>=0; j--){
            cout << "height pair: " << j << " " << height[j].first << " " << height[j].second << "\n";
            if (t[i]+w[i]-1 >= height[j].first){
                toremove.push_back(j);
                if (height[j].second > top){
                    top = height[j].second;
                }
            }
            else{
                break;
            }
        }
        for (int j = 0; j < toremove.size(); j++)
        {
            cout << "remove index: " << toremove[j] << "\n";
            height.erase(height.begin() + toremove[j]); //it removed the wrong one
        }
        cout << "newline\n"; 
        toremove.clear();
        height.push_back(make_pair(t[i], top+h[i]));
        if (top+h[i] > record){
            record = top+h[i];
        }
    }
    output << record << "\n";
 
 
}
