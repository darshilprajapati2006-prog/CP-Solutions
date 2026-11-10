
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
    char a[10][10];
    int sum = 0;

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> a[i][j];

            if(a[i][j] == 'X') {
                sum += min({i, j, 9-i, 9-j}) + 1;
            }
        }
    }

    cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
