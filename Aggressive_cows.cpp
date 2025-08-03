#include <bits/stdc++.h>
using namespace std;

bool canPlaceCows(vector<int> &stalls, int cows, int minDist) {
    int count = 1;  // First cow placed at first stall
    int lastPos = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPos >= minDist) {
            count++;
            lastPos = stalls[i];
        }
        if (count >= cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int cows) {
    sort(stalls.begin(), stalls.end());
    int low = 1;  // minimum possible distance is at least 1
    int high = stalls.back() - stalls[0];
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPlaceCows(stalls, cows, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, c;
        cin >> n >> c;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }

        int result = aggressiveCows(stalls, c);
        cout << result << endl;
    }

    return 0;
}
