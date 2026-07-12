// Sparse Table - RMQ (Range Minimum Query) estatico, sin updates
// O(n log n) build, O(1) query
#include <bits/stdc++.h>
using namespace std;

struct SparseTable {
    vector<vector<int>> table;
    vector<int> logs;
    int n;

    SparseTable(vector<int> &a) {
        n = a.size();
        int LOG = log2(n) + 1;
        table.assign(LOG, vector<int>(n));
        logs.assign(n + 1, 0);

        for (int i = 2; i <= n; i++) logs[i] = logs[i/2] + 1;

        table[0] = a;
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                table[j][i] = min(table[j-1][i], table[j-1][i + (1 << (j-1))]);
            }
        }
    }

    int query(int l, int r) { // minimo en [l, r], 0-indexed
        int j = logs[r - l + 1];
        return min(table[j][l], table[j][r - (1 << j) + 1]);
    }
};
