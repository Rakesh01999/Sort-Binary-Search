#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        pair<int, int> p[n];
        for (int i = 0; i < n; i++)
        {
            cin >> p[i].first >> p[i].second;
        }
        sort(p, p + n, [](pair<int, int> a, pair<int, int> b)
        {
            if (a.first != b.first)
            return a.first < b.first;
        return a.second > b.second;
        });
        for (auto it : p)
        {
            cout << it.first << " " << it.second << "\n";
        }
    }

    return 0;
}