# 📘 CP Notebook — Nivel Pupil Alto → Specialist

Notebook enfocado en lo que realmente aparece en ese rango de Codeforces (~1200-1400).
No incluye cosas de nivel Expert+ (flujo máximo, HLD, suffix automaton, etc.) a propósito.

## 📂 Estructura

```
cp-notebook/
├── template.cpp              # plantilla minimalista de contest
├── utils/
│   └── snippets.cpp          # trucos de STL: reverse, coord compression, etc.
├── data_structures/
│   ├── dsu.cpp                # Union-Find
│   ├── fenwick_tree.cpp       # BIT - suma de rango
│   ├── segment_tree.cpp       # rango con update puntual
│   └── sparse_table.cpp       # RMQ estatico O(1) query
├── graphs/
│   ├── bfs_dfs.cpp
│   ├── dijkstra.cpp           # caminos mas cortos, pesos no negativos
│   ├── floyd_warshall.cpp     # todos los pares, grafos pequenos
│   ├── topological_sort.cpp   # Kahn's algorithm
│   └── kruskal_mst.cpp        # Minimum Spanning Tree
├── dp/
│   ├── lis.cpp                # Longest Increasing Subsequence O(n log n)
│   ├── knapsack.cpp           # 0/1 Knapsack
│   └── coin_change.cpp
├── math/
│   ├── sieve_and_modpow.cpp
│   ├── gcd_extended_euclid.cpp
│   └── combinatorics_mod.cpp  # nCr mod p con factoriales precomputados
├── strings/
│   ├── kmp.cpp
│   └── hashing.cpp            # polynomial rolling hash
|   └── manacher.cpp     
└── misc/
    ├── binary_search_on_answer.cpp
    ├── two_pointers.cpp
    └── prefix_sums_2d.cpp
```

## 🧭 Cuándo usar qué (guía rápida)

| Situación en el problema | Herramienta |
|---|---|
| "suma/consulta de rango con updates" | Fenwick Tree o Segment Tree |
| "rango sin updates, muchas queries" | Sparse Table |
| "componentes conexas dinámicas" / Kruskal | DSU |
| "camino más corto, pesos positivos" | Dijkstra |
| "todos los pares de caminos más cortos, n pequeño" | Floyd-Warshall |
| "orden de dependencias" | Topological Sort |
| "respuesta monótona (si X funciona, X+1 también)" | Binary Search on Answer |
| "subarreglo contiguo con condición de suma" | Two Pointers |
| "comparar substrings rápido" | String Hashing |
| "buscar patrón en texto" | KMP |
| "nCr mod p, muchas consultas" | Combinatorics mod |
| "subsecuencia creciente más larga" | LIS |
| "maximizar valor con restricción de peso" | Knapsack |

## ✅ Cómo repasar esto

La idea es que entiendas *por qué* funciona cada uno, no solo copiarlo:
1. Antes de mirar el código, intenta explicar en una frase qué hace y su complejidad.
2. Busca 1-2 problemas de Codeforces por técnica (filtra por tag) y resuélvelos sin ver el notebook.
3. Si te atoras, usa el notebook como referencia, no como solución directa.
