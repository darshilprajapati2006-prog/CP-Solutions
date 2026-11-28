#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;

        if (a[0] == a[n - 1]) {
            cout << "NO\n";
            continue;
        }

        // move the max (last element) to the front, rest stay ascending
        rotate(a.begin(), a.end() - 1, a.end());

        cout << "YES\n";
        for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1];
    }
    return 0;
}