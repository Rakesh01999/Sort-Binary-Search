#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S, T;
    cin >> S >> T;

    if (S < T) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
