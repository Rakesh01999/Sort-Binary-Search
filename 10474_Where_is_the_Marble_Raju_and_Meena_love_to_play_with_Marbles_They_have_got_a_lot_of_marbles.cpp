#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    int caseNum = 1;
    while (cin >> N >> Q, N || Q) {
        vector<int> marbles(N);
        for (int i = 0; i < N; ++i) {
            cin >> marbles[i];
        }
        
        // Sort the marbles
        sort(marbles.begin(), marbles.end());

        cout << "CASE# " << caseNum++ << ":\n";

        while (Q--) {
            int query;
            cin >> query;

            // lower_bound returns an iterator to the first element >= query
            auto it = lower_bound(marbles.begin(), marbles.end(), query);
            
            if (it != marbles.end() && *it == query) {
                // +1 for 1-based index
                cout << query << " found at " << (it - marbles.begin() + 1) << '\n';
            } else {
                cout << query << " not found\n";
            }
        }
    }
    return 0;
}
