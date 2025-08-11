#include <bits/stdc++.h>
using namespace std;

bool canDistribute(vector<long long> &candies, long long K, long long mid) {
    long long count = 0;
    for (long long c : candies) {
        count += c / mid; // students from this box
        if (count >= K) return true; // early exit
    }
    return count >= K;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        long long K;
        cin >> N >> K;
        vector<long long> candies(N);
        long long maxCandy = 0;
        for (int i = 0; i < N; i++) {
            cin >> candies[i];
            maxCandy = max(maxCandy, candies[i]);
        }

        long long low = 1, high = maxCandy, ans = 0;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (canDistribute(candies, K, mid)) {
                ans = mid;      // possible, try bigger
                low = mid + 1;
            } else {
                high = mid - 1; // not possible, try smaller
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
