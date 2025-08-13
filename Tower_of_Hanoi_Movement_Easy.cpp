#include <bits/stdc++.h>
using namespace std;

void findMove(int n, long long a, char from, char aux, char to) {
    if (n == 1) {
        cout << "1 : " << from << " => " << to << "\n";
        return;
    }
    long long half = (1LL << (n - 1)) - 1; // moves in first part

    if (a <= half) {
        // Move lies in first phase
        findMove(n - 1, a, from, to, aux);
    } 
    else if (a == half + 1) {
        // This is the move of largest disk
        cout << n << " : " << from << " => " << to << "\n";
    } 
    else {
        // Move lies in second phase
        findMove(n - 1, a - (half + 1), aux, from, to);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        long long a;
        cin >> N >> a;
        findMove(N, a, 'A', 'B', 'C');
    }
    return 0;
}
