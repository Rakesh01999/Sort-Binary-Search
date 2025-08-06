#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); // Fast I/O
    cin.tie(nullptr);            // Disable C-style sync

    int T;
    cin >> T;

    for (int cs = 1; cs <= T; ++cs) {
        int n, q;
        cin >> n >> q;

        vector<int> points(n);
        for (int i = 0; i < n; ++i) {
            cin >> points[i];
        }

        cout << "Case " << cs << ":\n";
        while (q--) {
            int A, B;
            cin >> A >> B;
          
            // Use binary search (lower_bound and upper_bound)
            int left = lower_bound(points.begin(), points.end(), A) - points.begin();
            int right = upper_bound(points.begin(), points.end(), B) - points.begin();

            cout << (right - left) << '\n';
        }
    }
    return 0;
}
