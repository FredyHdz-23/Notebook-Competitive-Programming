// Combinatoria modular: factoriales precomputados + nCr mod p (p primo)
// O(n) precompute, O(1) por consulta de nCr
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 200005;
const ll MOD = 1e9 + 7;

ll fact[MAXN], invFact[MAXN];

ll modpow(ll base, ll exp, ll mod) {
    ll result = 1; base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

void precomputeFactorials() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) fact[i] = fact[i-1] * i % MOD;
    invFact[MAXN-1] = modpow(fact[MAXN-1], MOD-2, MOD);
    for (int i = MAXN-2; i >= 0; i--) invFact[i] = invFact[i+1] * (i+1) % MOD;
}

ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n-r] % MOD;
}
