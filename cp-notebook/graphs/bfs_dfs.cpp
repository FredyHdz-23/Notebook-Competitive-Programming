// BFS y DFS estandar
// O(V + E)
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> distBfs;

void bfs(int src) {
    fill(visited.begin(), visited.end(), false);
    fill(distBfs.begin(), distBfs.end(), -1);

    queue<int> q;
    q.push(src);
    visited[src] = true;
    distBfs[src] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                distBfs[v] = distBfs[u] + 1;
                q.push(v);
            }
        }
    }
}

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) dfs(v);
    }
}
