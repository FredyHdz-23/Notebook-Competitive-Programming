// Prefix Sums 2D - suma de submatriz en O(1) tras O(n*m) precompute
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>> build2DPrefix(vector<vector<ll>> &a, int n, int m) {
    vector<vector<ll>> pre(n + 1, vector<ll>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pre[i][j] = a[i-1][j-1] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
        }
    }
    return pre;
}

// suma de la submatriz con esquinas (r1,c1) a (r2,c2), 1-indexed, inclusive
ll querySum2D(vector<vector<ll>> &pre, int r1, int c1, int r2, int c2) {
    return pre[r2][c2] - pre[r1-1][c2] - pre[r2][c1-1] + pre[r1-1][c1-1];
}
