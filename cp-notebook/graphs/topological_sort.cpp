// Topological Sort (Kahn's algorithm, BFS based)
// O(V + E). Sirve tambien para detectar ciclos en grafo dirigido.
#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int n, vector<vector<int>> &adj) {
    vector<int> indeg(n + 1, 0);
    for (int u = 1; u <= n; u++)
        for (int v : adj[u]) indeg[v]++;

    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (indeg[i] == 0) q.push(i);

    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adj[u]) {
            if (--indeg[v] == 0) q.push(v);
        }
    }

    if ((int)order.size() != n) return {}; // hay ciclo, no existe orden topologico
    return order;
}
