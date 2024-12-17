#include "weigh.h"
#include <cstdio>
#include <bits/stdc++.h>
#define MAX_N 10000
using namespace std;
int N;
int weighme[MAX_N];
typedef long long ll;
// An example according to the sample session
void init()
{
    N = getN();
    // keep separating the diamonds into two groups based on ith bit
    // if groups have the same weight: keep going
    // else binary search both groups for the diamond in each
    ll totalweight = 10 * N;
    vector<int> group1;
    vector<int> group2;
    ll weightg1;
    int group1cnt;
    vector<int> bitdiff;
    int specialweight;
    bool flag = false;
    int specialcnt;
    for (int i = 0; i < 15; i++)
    {
        group1cnt = 0;
        for (int j = 1; j <= N; j++)
        {
            if (j & (1 << i))
            {
                weighme[group1cnt] = j;
                group1cnt++;
            }
        }
        weightg1 = weight(group1cnt, weighme);
        if (weightg1 == 10*group1cnt)
        {
            bitdiff.push_back(0);
            continue;
        }
        else
        {
            bitdiff.push_back(1);
            if (flag){
                continue;
            }
            specialweight = weightg1;
            specialcnt = group1cnt;
            for (int j = 1; j <= N; j++)
            {
                if (j & (1 << i))
                {
                    group1.push_back(j);
                }
                else
                {
                    group2.push_back(j);
                }
            }
            flag = true;
        }
    }
    // there is one diamond in group1 and one in group2
    int firstdiamond = -1;
    int l1 = 0;
    int r1 = group1.size() - 1;
    while (l1 <= r1)
    {
        int mid = (l1 + r1) / 2;
        // check from l1 to mid
        for (int i = l1; i <= mid; i++)
        {
            weighme[i - l1] = group1[i];
        }
        ll weight1;
        weight1 = weight(mid - l1 + 1, weighme);
        if (weight1 % 10 == 0)
        {
            // the diamond is not in this range
            l1 = mid + 1;
        }
        else
        {
            // the diamond is in this range
            firstdiamond = group1[mid];
            r1 = mid-1;
        }
    }
    int seconddiamond = firstdiamond;
    for (int i = 0; i < 15; i++){
        if (bitdiff[i] == 1){
            //change the ith bit of second diamond
            seconddiamond = seconddiamond ^ (1 << i);
        }
    }
    if (specialweight < 10*specialcnt)
    {
        diamonds(firstdiamond, seconddiamond);
    }
    else
    {
        diamonds(seconddiamond, firstdiamond);
    }
}
Test Results
