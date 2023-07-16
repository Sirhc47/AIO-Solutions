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
        file(pow2);
        int carry = 0;
        deque<int> num;
        num.push_back(1);
        string n;
        cin >> n;
        if (n == "1"){
            cout << 0;
            return 0;
        }
        int power = 0;
        string sus = "";
        while (power < 9999){
            power++;
            deque<int> temp;
            for (int i = num.size()-1; i>=0; i--){
                temp.push_front((2*num.back())%10 + carry);
                carry = 0;
                if (num.back() >= 5){
                    carry = 1;
                }
                num.pop_back();
            }
            if (carry){
                temp.push_front(1);
            }
            carry = 0;
            num = temp;
            sus.clear();
            while (temp.size()){
                sus.push_back(temp.front()+'0');
                temp.pop_front();
            }
            if (sus.find(n) != string::npos){ 
                cout << power;
                return 0;
            }

        }
        cout << "No solution found";

    }
