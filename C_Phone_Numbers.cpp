#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    // Step 1: get sorted unique letters
    set<char> st(s.begin(), s.end());
    vector<char> letters(st.begin(), st.end());

    if (k > n) {
        // Case 1: just append smallest char until length k
        cout << s;
        for (int i = n; i < k; i++) cout << letters[0];
        cout << "\n";
        return 0;
    }

    // Case 2: modify s
    string t = s.substr(0, k); // start with first k chars of s

    // Go from right to left to find position to change
    for (int i = k - 1; i >= 0; i--) {
        // find next larger letter than t[i] in letters[]
        auto it = upper_bound(letters.begin(), letters.end(), t[i]);
        if (it != letters.end()) {
            t[i] = *it; // replace with next bigger char
            // fill rest with smallest char
            for (int j = i + 1; j < k; j++) t[j] = letters[0];
            cout << t << "\n";
            return 0;
        }
    }
}
