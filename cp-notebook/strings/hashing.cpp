// String Hashing (polynomial rolling hash) - comparar substrings en O(1)
// tras O(n) precompute. Util para: comparar substrings, detectar palindromos,
// substring matching rapido
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const ll BASE = 131;

struct StringHash {
    vector<ll> hashVal, power;

    StringHash(string &s) {
        int n = s.size();
        hashVal.assign(n + 1, 0);
        power.assign(n + 1, 1);

        for (int i = 0; i < n; i++) {
            hashVal[i+1] = (hashVal[i] * BASE + s[i]) % MOD;
            power[i+1] = (power[i] * BASE) % MOD;
        }
    }

    // hash del substring [l, r], 0-indexed, inclusive
    ll getHash(int l, int r) {
        ll res = (hashVal[r+1] - hashVal[l] * power[r-l+1]) % MOD;
        if (res < 0) res += MOD;
        return res;
    }
};

// Nota: para reducir colisiones en problemas dificiles, usar doble hashing
// (dos MOD y BASE distintos) y combinar (h1, h2) como par.
