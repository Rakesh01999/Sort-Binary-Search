#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

bool canEatAll(const vector<ll>& A, ll H, ll K) {
    ll totalHours = 0;
    for (ll bananas : A) {
        totalHours += (bananas + K - 1) / K;  // ceil(bananas / K)
    }
    return totalHours <= H;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll N, H;
        cin >> N >> H;
        vector<ll> A(N);
        ll maxBananas = 0;
        for (ll i = 0; i < N; i++) {
            cin >> A[i];
            maxBananas = max(maxBananas, A[i]);
        }

        // Binary search for the minimum possible K
        ll low = 1, high = maxBananas, result = maxBananas;

        while (low <= high) {
            ll mid = low + (high - low) / 2;
            if (canEatAll(A, H, mid)) {
                result = mid;  
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << result << endl;
    }

    return 0;
}
