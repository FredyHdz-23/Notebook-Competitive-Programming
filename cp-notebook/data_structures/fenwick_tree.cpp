// Fenwick Tree (BIT) - suma de prefijos con update puntual
// O(log n) por operacion
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Fenwick {
    int n;
    vector<ll> tree;

    Fenwick(int n) : n(n), tree(n + 1, 0) {}

    void update(int i, ll delta) {
        for (; i <= n; i += i & (-i)) tree[i] += delta;
    }

    ll query(int i) { // suma [1, i]
        ll s = 0;
        for (; i > 0; i -= i & (-i)) s += tree[i];
        return s;
    }

    ll query(int l, int r) { return query(r) - query(l - 1); } // suma [l, r]
};
