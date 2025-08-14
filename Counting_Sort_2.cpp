#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n; // number of elements
    vector<int> arr(n);
    int maxVal = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    vector<int> count(maxVal + 1, 0);

    // Step 1: Count occurrences
    for (int x : arr) {
        count[x]++;
    }

    // Step 2: Output sorted array
    bool first = true;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i] > 0) {
            if (!first) cout << " ";
            cout << i;
            first = false;
            count[i]--;
        }
    }
    cout << "\n";

    return 0;
}
