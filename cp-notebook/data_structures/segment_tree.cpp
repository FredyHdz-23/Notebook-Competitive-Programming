// Segment Tree - min/suma de rango con update puntual
// O(log n) query/update, O(n) build
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct SegTree {
    int n;
    vector<ll> tree;

    SegTree(int n) : n(n), tree(4 * n, 0) {}

    void build(vector<ll> &a, int node, int start, int end) {
        if (start == end) { tree[node] = a[start]; return; }
        int mid = (start + end) / 2;
        build(a, 2*node, start, mid);
        build(a, 2*node+1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node+1]; // cambiar a min/max si aplica
    }

    void update(int node, int start, int end, int idx, ll val) {
        if (start == end) { tree[node] = val; return; }
        int mid = (start + end) / 2;
        if (idx <= mid) update(2*node, start, mid, idx, val);
        else update(2*node+1, mid+1, end, idx, val);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    ll query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0; // neutro: 0 para suma, INF para min
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return query(2*node, start, mid, l, r) + query(2*node+1, mid+1, end, l, r);
    }
};
