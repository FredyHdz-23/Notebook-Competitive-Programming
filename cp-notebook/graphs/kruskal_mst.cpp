// Kruskal - Minimum Spanning Tree usando DSU
// O(E log E)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct DSU {
    vector<int> parent, sz;
    DSU(int n) { parent.resize(n+1); sz.assign(n+1,1); iota(parent.begin(), parent.end(), 0); }
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
    bool unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return false;
        if (sz[rx] < sz[ry]) swap(rx, ry);
        parent[ry] = rx; sz[rx] += sz[ry];
        return true;
    }
};

struct Edge { int u, v; ll w; };

ll kruskal(int n, vector<Edge> &edges) {
    sort(edges.begin(), edges.end(), [](Edge &a, Edge &b) { return a.w < b.w; });
    DSU dsu(n);
    ll totalWeight = 0;
    int edgesUsed = 0;

    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            totalWeight += e.w;
            edgesUsed++;
        }
    }

    if (edgesUsed != n - 1) return -1; // el grafo no es conexo
    return totalWeight;
}
