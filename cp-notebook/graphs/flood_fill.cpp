// Complejidad: O(n*m)

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

vector<vector<int>> grid; // grid[i][j] = valor de la celda
vector<vector<bool>> vis;
int n, m;

void floodFillBFS(int si, int sj) {
    queue<pair<int,int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny]) continue;
            if (grid[nx][ny] != grid[x][y]) continue; // condición de "misma región"

            vis[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}


// Contar componentes / regiones (ej: número de islas)
int countRegions() {
    vis.assign(n, vector<bool>(m, false));
    int regions = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && grid[i][j] == 1) { // condición según problema
                floodFillBFS(i, j);
                regions++;
            }
        }
    }
    return regions;
}
