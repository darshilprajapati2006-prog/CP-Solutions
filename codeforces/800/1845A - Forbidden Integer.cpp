#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define MIN_IN(A) (*min_element(all(A)))
#define MAX_IN(A) (*max_element(all(A)))
#define MIN_AT(A) (min_element(all(A)) - (A).begin())
#define MAX_AT(A) (max_element(all(A)) - (A).begin())
#define COUNT(V, A) count(all(V), (A))
#define GCD(a, b) __gcd((a), (b))
#define LCM(a, b) ((ll)(a) / __gcd((ll)(a), (ll)(b)) * (b))
#define SORT(A) sort(all(A))
#define RSORT(A) sort(all(A), greater<>())
#define REVERSE(A) reverse(all(A))

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    if (x != 1) {
        cout << "YES\n";
        cout << n << '\n';
        for (int i = 0; i < n; i++) {
            cout << 1 << " ";
        }
        cout << '\n';
    }
    else if (k == 1) {
        cout << "NO\n";
    }
    else if (n % 2 == 0) {
        cout << "YES\n";
        cout << n / 2 << '\n';
        for (int i = 0; i < n / 2; i++) {
            cout << 2 << " ";
        }
        cout << '\n';
    }
    else if (k >= 3) {
        cout << "YES\n";
        cout << n / 2 << '\n';
        cout << 3 << " ";
        for (int i = 0; i < n / 2 - 1; i++) {
            cout << 2 << " ";
        }
        cout << '\n';
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}