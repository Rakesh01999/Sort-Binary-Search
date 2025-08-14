#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        string order;
        cin >> order;
        vector<int> pos(26); // position of each letter in custom order
        for (int i = 0; i < 26; i++) {
            pos[order[i] - 'a'] = i;
        }

        string A, B;
        cin >> A >> B;
        char result = '='; // assume equal unless proven otherwise

        for (int i = 0; i < (int)A.size(); i++) {
            if (pos[A[i] - 'a'] < pos[B[i] - 'a']) {
                result = '<';
                break;
            } else if (pos[A[i] - 'a'] > pos[B[i] - 'a']) {
                result = '>';
                break;
            }
        }

        cout << result << "\n";
    }
    return 0;
}
