// Two Pointers - ejemplo: contar subarreglos con suma <= S (todos positivos)
// O(n)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll countSubarraysSumAtMostS(vector<ll> &a, ll S) {
    int n = a.size();
    ll count = 0, sum = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        sum += a[right];
        while (sum > S) {
            sum -= a[left];
            left++;
        }
        count += (right - left + 1); // # subarreglos que terminan en "right"
    }
    return count;
}
