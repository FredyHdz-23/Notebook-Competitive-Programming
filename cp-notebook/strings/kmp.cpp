// KMP - busqueda de patron en texto
// O(n + m)
#include <bits/stdc++.h>
using namespace std;

vector<int> buildPrefixFunction(string &pattern) {
    int m = pattern.size();
    vector<int> pi(m, 0);
    for (int i = 1; i < m; i++) {
        int j = pi[i - 1];
        while (j > 0 && pattern[i] != pattern[j]) j = pi[j - 1];
        if (pattern[i] == pattern[j]) j++;
        pi[i] = j;
    }
    return pi;
}

vector<int> kmpSearch(string &text, string &pattern) {
    vector<int> pi = buildPrefixFunction(pattern);
    vector<int> occurrences;
    int j = 0;
    for (int i = 0; i < (int)text.size(); i++) {
        while (j > 0 && text[i] != pattern[j]) j = pi[j - 1];
        if (text[i] == pattern[j]) j++;
        if (j == (int)pattern.size()) {
            occurrences.push_back(i - j + 1);
            j = pi[j - 1];
        }
    }
    return occurrences;
}
