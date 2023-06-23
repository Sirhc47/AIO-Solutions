#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main()
{
    int d;
    int c;
    int p1;
    int c1;
    int p2;
    int c2;
    int ans;
    int cookies = 0;
    bool fac1bought = false;
    bool fac2bought = false;
    ifstream input("cookiesin.txt");
    ofstream output("cookiesout.txt");
    input >> d >> c >> p1 >> c1 >> p2 >> c2;
 
 
    int cookiesin = c;
    for (int day = 1; day <= d; day++) {
        cookies += cookiesin;
        cout << cookies << " " << day << "\n";
        if (cookies >= p1 && !fac1bought) {
            if ((d - day) * c1 >= p1) {
                fac1bought = true;
                cookies -= p1;
                cookiesin += c1;
            }
        }
        if (cookies >= p2 && !fac2bought && fac1bought) {
            if ((d - day) * c2 >= p2) {
                fac2bought = true;
                cookies -= p2;
                cookiesin += c2;
            }
        }
    }
    int ans1 = cookies;
 
 
    fac1bought = false;
    fac2bought = false;
    cookies = 0;
    cookiesin = c;
    for (int day = 1; day <= d; day++) {
        cookies += cookiesin;
        cout << cookies << " " << day << "\n";
        if (cookies >= p2 && !fac2bought) {
            if ((d - day) * c2 >= p2) {
                fac2bought = true;
                cookies -= p2;
                cookiesin += c2;
            }
        }
        if (cookies >= p1 && !fac1bought && fac2bought) {
            if ((d - day) * c1 >= p1) {
                fac1bought = true;
                cookies -= p1;
                cookiesin += c1;
            }
        }
 
    }
    int ans2 = cookies;
 
    fac1bought = false;
    fac2bought = false;
    cookies = 0;
    cookiesin = c;
    for (int day = 1; day <= d; day++) {
        cookies += cookiesin;
        cout << cookies << " " << day << "\n";
        if (cookies >= p2 && !fac2bought) {
            if ((d - day) * c2 >= p2) {
                fac2bought = true;
                cookies -= p2;
                cookiesin += c2;
            }
        }
    }
    int ans3 = cookies;
 
    fac1bought = false;
    fac2bought = false;
    cookies = 0;
    cookiesin = c;
 
    for (int day = 1; day <= d; day++) {
        cookies += cookiesin;
        cout << cookies << " " << day << "\n";
        if (cookies >= p1 && !fac1bought) {
            if ((d - day) * c1 >= p1) {
                fac1bought = true;
                cookies -= p1;
                cookiesin += c1;
            }
        }
    }
    int ans4 = cookies;
    ans = max(c*d, max(max(ans1, ans2), max(ans3, ans4)));
    output << ans << "\n";
    input.close();
    output.close();
    return 0;
 
}
