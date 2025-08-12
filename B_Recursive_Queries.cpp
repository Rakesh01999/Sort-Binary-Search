#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 5;
int cnt[10][MAX]; // cnt[k][i] = count of g(x) == k for x in [1..i]

// Correct g(x) function: skips zeros in digit product
int g(int x) {
    while (x >= 10) {
        int prod = 1;
        while (x > 0) {
            int d = x % 10;
            if (d != 0) prod *= d;
            x /= 10;
        }
        x = prod;
    }
    return x;
}

// Precompute g(x) and build prefix sums
void preprocess() {
    for (int i = 1; i < MAX; ++i) {
        int val = g(i);
        for (int k = 1; k <= 9; ++k) {
            cnt[k][i] = cnt[k][i - 1] + (val == k);
        }
    }
}

// Answer each query in O(1)
int query(int l, int r, int k) {
    return cnt[k][r] - cnt[k][l - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    preprocess();

    int Q;
    cin >> Q;
    while (Q--) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << query(l, r, k) << '\n';
    }

    return 0;
}
