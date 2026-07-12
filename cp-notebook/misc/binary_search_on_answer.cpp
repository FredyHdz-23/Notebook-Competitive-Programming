// Binary Search on the Answer
// Uso: cuando feasible(x) es monotona (false...false true...true)
// O(log(rango) * costo_feasible)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool feasible(ll x) {
    // implementar segun el problema
    return true; // placeholder
}

ll binarySearchAnswer(ll lo, ll hi) {
    // encuentra el MENOR x que cumple feasible(x) == true
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (feasible(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}
