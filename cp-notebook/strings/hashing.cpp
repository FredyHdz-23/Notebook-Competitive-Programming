// String Hashing (polynomial rolling hash) - comparar substrings en O(1)
// tras O(n) precompute. Util para: comparar substrings, detectar palindromos,
// substring matching rapido
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

const ull MOD = (1ULL << 61) - 1;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ull BASE = rng() % (MOD - 1000) + 500;

ull mulmod(ull a, ull b) {
    __uint128_t t = (__uint128_t)a * b;
    ull r = (ull)(t & MOD) + (ull)(t >> 61);
    return r >= MOD ? r - MOD : r;
}

struct Hash {
    vector<ull> h, pw;
    Hash() {}
    Hash(const string& s) { build(s); }

    void build(const string& s) {
        int n = s.size();
        h.assign(n + 1, 0);
        pw.assign(n + 1, 1);
        for (int i = 0; i < n; i++) {
            h[i + 1] = mulmod(h[i], BASE) + (unsigned char)s[i] + 1;
            if (h[i + 1] >= MOD) h[i + 1] -= MOD;
            pw[i + 1] = mulmod(pw[i], BASE);
        }
    }

    ull get(int l, int r) const {
        ull x = h[r] + MOD - mulmod(h[l], pw[r - l]);
        return x >= MOD ? x - MOD : x;
    }
};

(mulmod(ha, pw[lenB]) + hb) % MOD //concatenar dos hashes

// Nota: para reducir colisiones en problemas dificiles, usar doble hashing
// (dos MOD y BASE distintos) y combinar (h1, h2) como par.
