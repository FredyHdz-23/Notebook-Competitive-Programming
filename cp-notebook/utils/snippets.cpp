/*
 * Snippets sueltos que sirven a cada rato, sin necesidad de plantilla propia.
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    // ---- Vector en reversa ----
    vector<int> v = {1, 2, 3, 4, 5};
    reverse(v.begin(), v.end());
    // o recorrerlo en reversa sin modificarlo:
    for (auto it = v.rbegin(); it != v.rend(); it++) {
        // *it
    }

    // ---- Ordenar de mayor a menor ----
    sort(v.rbegin(), v.rend());
    // o con comparador:
    sort(v.begin(), v.end(), greater<int>());

    // ---- Eliminar duplicados (vector ordenado) ----
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    // ---- Suma de un vector ----
    long long suma = accumulate(v.begin(), v.end(), 0LL);

    // ---- Maximo / minimo con indice ----
    int idxMax = max_element(v.begin(), v.end()) - v.begin();
    int idxMin = min_element(v.begin(), v.end()) - v.begin();

    // ---- Busqueda binaria (vector ordenado) ----
    bool existe = binary_search(v.begin(), v.end(), 3);
    int cntMenores = lower_bound(v.begin(), v.end(), 3) - v.begin(); // # elementos < 3
    int cntMenoresIguales = upper_bound(v.begin(), v.end(), 3) - v.begin(); // # elementos <= 3

    // ---- Siguiente permutacion ----
    vector<int> p = {1, 2, 3};
    do {
        // usar p
    } while (next_permutation(p.begin(), p.end()));

    // ---- Comprimir coordenadas (coordinate compression) ----
    vector<int> a = {50, 10, 40, 10, 30};
    vector<int> comp = a;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    for (int &x : a) {
        x = lower_bound(comp.begin(), comp.end(), x) - comp.begin(); // ahora son indices 0..k-1
    }

    // ---- Leer vector rapido ----
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;

    // ---- Pair con estructura bindada (C++17) ----
    pair<int,int> pr = {1, 2};
    auto [a1, b1] = pr;

    // ---- Comparador custom para sort de pares ----
    vector<pair<int,int>> vp = {{1,5},{2,3}};
    sort(vp.begin(), vp.end(), [](pair<int,int> &a, pair<int,int> &b) {
        return a.second < b.second; // ordenar por segundo elemento
    });

    // ---- gcd / lcm builtin (C++17) ----
    int g = __gcd(12, 18);
    long long l = (12LL * 18LL) / __gcd(12, 18);

    // ---- Contar bits en 1 ----
    int bits = __builtin_popcount(13); // para int
    // __builtin_popcountll(x) para long long

    return 0;
}
