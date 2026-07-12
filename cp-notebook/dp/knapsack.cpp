// 0/1 Knapsack
// O(n * W)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll knapsack(int n, ll W, vector<ll> &weight, vector<ll> &value) {
    vector<ll> dp(W + 1, 0);
    for (int i = 0; i < n; i++) {
        for (ll w = W; w >= weight[i]; w--) {
            dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
        }
    }
    return dp[W];
}
