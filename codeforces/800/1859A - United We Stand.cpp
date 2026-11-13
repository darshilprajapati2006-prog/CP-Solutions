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
    cin>>n;
    vector<int> v(n),b,c;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int mn = MIN_IN(v);
    for(int i=0;i<n;i++){
        if(v[i] == mn) b.push_back(v[i]);
        else c.push_back(v[i]);
    }
    if(c.empty()) {
        cout<<-1<<'\n';
        return;
    }
    cout<<b.size()<<" "<<c.size()<<'\n';
    for(int j=0;j<b.size();j++){
        cout<<b[j]<<" ";
    }
    cout<<'\n';
    for(int k=0;k<c.size();k++){
        cout<<c[k]<<" ";
    }
    cout<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}