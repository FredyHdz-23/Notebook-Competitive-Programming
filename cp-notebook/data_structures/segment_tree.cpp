// Segment Tree - min/suma de rango con update puntual
// O(log n) query/update, O(n) build
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// iterativo mas corto
struct segTree{
    vector<ll> v; int n; ll nulo = 0;
    ll op(ll a, ll b) {return a+b;}
    segTree (int n) : n(n) {v.assign(2*n,nulo);}
    void upd(int i, ll nv){
        for (v[i+=n]=nv; i>1; i>>=1) v[i>>1] = op(v[i],v[i^1]);
    }
    ll get(int l, int r){
        ll vl = nulo, vr = nulo;
        for (l+=n, r+=n+1; l<r; l>>=1, r>>=1){
            if (l&1) vl = op(vl,v[l++]);
            if (r&1) vr = op(v[--r], vr);
        }
        return op(vl,vr);
    }
};

//recursivo mas largo
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
