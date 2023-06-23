#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
using namespace std;
int main(){
    ifstream input("stacksin.txt");
    ofstream output("stacksout.txt");
    stack<int> s;
    int x;
    while (input >> x){
        if (x == -2){
            break;
        }
        if (x ==  -1){
            if (!s.size() == 0){
                s.pop();
            }
 
        }
        else{
            s.push(x);
        }
        if (!s.empty()){
            stack<int> copy = s;
            vector<int> temp;
            while (!copy.empty())
            {
                temp.push_back(copy.top());
                copy.pop();
            }
            for (int i = temp.size() - 1; i >= 0; i--)
            {
                output << temp[i] << " ";
            }
            output << "\n";
        }
        else{
            output << "stack is empty!\n";
        }
    }
 
}
