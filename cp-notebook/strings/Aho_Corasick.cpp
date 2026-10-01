struct AhoCorasick {
    struct Node {
        int next[26], go[26], fail = 0;
        int cnt = 0;          // visitas directas durante el recorrido del texto
        vector<int> wordsHere; // ids de patrones que terminan aquí
        Node() { fill(next, next+26, -1); fill(go, go+26, -1); }
    };
    vector<Node> t{Node()};

    void addString(const string& s, int id) {
        int cur = 0;
        for (char c : s) {
            int ch = c - 'a';
            if (t[cur].next[ch] == -1) { t[cur].next[ch] = t.size(); t.push_back(Node()); }
            cur = t[cur].next[ch];
        }
        t[cur].wordsHere.push_back(id);
    }

    void build() {
        queue<int> q;
        for (int c = 0; c < 26; c++) {
            if (t[0].next[c] == -1) t[0].go[c] = 0;
            else { int v = t[0].next[c]; t[v].fail = 0; t[0].go[c] = v; q.push(v); }
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int c = 0; c < 26; c++) {
                int v = t[u].next[c];
                if (v == -1) t[u].go[c] = t[t[u].fail].go[c];
                else { t[v].fail = t[t[u].fail].go[c]; t[u].go[c] = v; q.push(v); }
            }
        }
    }

    void markText(const string& text) {
        int cur = 0;
        for (char c : text) {
            cur = t[cur].go[c - 'a'];
            t[cur].cnt++; // marca visita en el nodo exacto
        }
    }

    // NUEVO: propaga las visitas hacia arriba por el árbol de fail links
    // (ordena los nodos por profundidad de fail descendente, o usa el orden
    // en que se agregaron al BFS de build — ambos funcionan si guardas el orden)
    vector<int> bfsOrder; // guarda el orden del BFS en build() para reusar aquí

    void propagate() {
        for (int i = (int)bfsOrder.size() - 1; i >= 0; i--) {
            int u = bfsOrder[i];
            t[t[u].fail].cnt += t[u].cnt;
        }
    }

    vector<int> getCounts(int numPatterns) {
        vector<int> res(numPatterns, 0);
        for (int node = 0; node < (int)t.size(); node++)
            for (int id : t[node].wordsHere)
                res[id] = t[node].cnt;
        return res;
    }
};
