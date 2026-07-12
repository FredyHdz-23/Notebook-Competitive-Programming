// Criba de Eratostenes + Exponenciacion modular rapida
// O(n log log n) criba, O(log b) modpow
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; (ll)i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) isPrime[j] = false;
        }
    }
    return isPrime;
}

ll modpow(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

// inverso modular (mod debe ser primo, usa Fermat)
ll modInverse(ll a, ll mod) {
    return modpow(a, mod - 2, mod);
}
