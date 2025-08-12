#include <iostream>
using namespace std;

string build(int n) {
    if (n == 1) return "A";
    string prev = build(n - 1);
    char mid = 'A' + n - 1;
    return prev + mid + prev;
}

int main() {
    int N;
    cin >> N;
    cout << build(N);
    return 0;
}
