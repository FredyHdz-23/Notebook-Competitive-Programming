// sa[i] = posición donde empieza el i-ésimo sufijo en orden lexicográfico
// lcp[i] = longitud del prefijo común entre sa[i] y sa[i-1]
struct SuffixArray {
    string s;
    int n;
    vector<int> sa, rnk, lcp;

    SuffixArray(string str) : s(str + '$'), n(s.size()) {
        build();
        buildLCP();
    }

    void build() {
        sa.resize(n);
        rnk.resize(n);
        vector<int> tmp(n);
        iota(sa.begin(), sa.end(), 0);
        for (int i = 0; i < n; i++) rnk[i] = s[i];

        for (int k = 1; k < n; k <<= 1) {
            auto cmp = [&](int a, int b) {
                if (rnk[a] != rnk[b]) return rnk[a] < rnk[b];
                int ra = a + k < n ? rnk[a + k] : -1;
                int rb = b + k < n ? rnk[b + k] : -1;
                return ra < rb;
            };
            sort(sa.begin(), sa.end(), cmp);

            tmp[sa[0]] = 0;
            for (int i = 1; i < n; i++)
                tmp[sa[i]] = tmp[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
            rnk = tmp;

            if (rnk[sa[n - 1]] == n - 1) break; // ya todos distintos
        }
    }

    void buildLCP() {
        lcp.assign(n, 0);
        vector<int> inv(n);
        for (int i = 0; i < n; i++) inv[sa[i]] = i;

        int k = 0;
        for (int i = 0; i < n; i++) {
            if (inv[i] == 0) { k = 0; continue; }
            int j = sa[inv[i] - 1];
            while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
            lcp[inv[i]] = k;
            if (k) k--;
        }
    }
};
