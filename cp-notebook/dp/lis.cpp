// Longest Increasing Subsequence (LIS)
// O(n log n)
#include <bits/stdc++.h>
using namespace std;

int lis(vector<int> &a) {
    vector<int> tails;
    for (int x : a) {
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) tails.push_back(x);
        else *it = x;
    }
    return tails.size();
}
