// Floyd-Warshall - todos los pares de caminos mas cortos
// O(V^3), sirve para grafos pequenos o con pesos negativos (sin ciclos negativos)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

void floydWarshall(vector<vector<ll>> &dist, int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    // deteccion de ciclo negativo: si dist[i][i] < 0 para algun i
}
