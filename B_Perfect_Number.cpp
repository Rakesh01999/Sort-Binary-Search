#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int count = 0;
    for (int i = 19; ; i++) {
        int temp = i, sum = 0;
        while (temp) {
            sum += temp % 10;
            temp /= 10;
        }
        if (sum == 10) count++;
        if (count == n) {
            cout << i << endl;
            break;
        }
    }
}
