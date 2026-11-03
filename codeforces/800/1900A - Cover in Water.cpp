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
    int n;
    string s;
    cin>>n>>s;
    if(s.find("...") != -1) cout<<2<<'\n';
    else cout<<COUNT(s,'.')<<'\n';
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}


/*
APPROCH :
Steps:
1. Read the number of test cases t.
2. For each test case, read n and the string s.
3. Check if s contains three consecutive empty cells "..." using s.find("...").
4. If "..." exists, print 2. The middle cell of "..." refills itself, so its water can be moved to any other empty cell with action 2 (free).
5. Otherwise, print the total count of '.' in s, since each empty cell needs action 1 separately.

Time Complexity : O(n) per test case
Space Complexity : O(1)
note: Answer is either 2 (if "..." is present) or the number of empty cells.
*/
