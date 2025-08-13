#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> prefix(n);

    // Read piles and compute prefix sums
    for (int i = 0; i < n; i++) {
        long long worms;
        cin >> worms;
        if (i == 0) prefix[i] = worms;
        else prefix[i] = prefix[i - 1] + worms;
    }

    int m;
    cin >> m;
    while (m--) {
        long long q;
        cin >> q;

        // Find first pile whose end label >= q
        int idx = lower_bound(prefix.begin(), prefix.end(), q) - prefix.begin();

        // Output pile number (1-indexed)
        cout << idx + 1 << "\n";
    }

    return 0;
}
