// GCD / LCM / Extended Euclidean Algorithm
// O(log min(a,b))
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); } // o usar __gcd built-in
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

// Encuentra x, y tal que a*x + b*y = gcd(a,b)
ll extendedGcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    ll x1, y1;
    ll g = extendedGcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}
