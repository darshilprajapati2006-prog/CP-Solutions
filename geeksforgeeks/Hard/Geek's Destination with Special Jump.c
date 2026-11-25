class Solution {
    typedef long long ll;
    static const ll MOD = 1000000007LL;

    // sum_{y=1..n} ceil(y / c)
    ll S(ll n, ll c) {
        if (n <= 0) return 0;
        ll q = n / c, rem = n % c;
        ll res = c * (q * (q + 1) / 2) + rem * (q + 1);   // fits in long long
        return res % MOD;
    }

public:
    int minTime(int a, int b, int d, int l, int r) {
        ll c = a - b;
        ll cnt = (ll)r - l + 1;

        // sum of (x + 1) for x in [d-r, d-l]
        ll first = (ll)d - r, last = (ll)d - l;
        ll sumX = (first + last) * cnt / 2;               // <= ~1e16, fits
        ll ans = (sumX % MOD + cnt % MOD) % MOD;

        // sum of k(x) for x in [d-r, d-l], k(x) = ceil((x-a)/c) for x > a
        ll lo = max(1LL, first - a);
        ll hi = last - a;
        if (hi >= 1) {
            ll K = ((S(hi, c) - S(lo - 1, c)) % MOD + MOD) % MOD;
            ans = (ans + 2LL * b % MOD * K) % MOD;
        }
        return (int)ans;
    }
};