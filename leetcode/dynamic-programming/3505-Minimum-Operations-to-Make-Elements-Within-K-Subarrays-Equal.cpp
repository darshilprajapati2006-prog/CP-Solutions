class Solution {
public:
    long long minOperations(vector<int>& v, int x, int k) {
        int n = v.size();
        multiset<long long> lo, hi;
        long long sumLo = 0, sumHi = 0;
        int loSize = (x + 1) / 2;

        auto rebalance = [&]() {
            while ((int)lo.size() > loSize) {
                auto it = prev(lo.end());
                long long val = *it;
                lo.erase(it);
                sumLo -= val;
                hi.insert(val);
                sumHi += val;
            }
            while ((int)lo.size() < loSize && !hi.empty()) {
                auto it = hi.begin();
                long long val = *it;
                hi.erase(it);
                sumHi -= val;
                lo.insert(val);
                sumLo += val;
            }
        };
        auto add = [&](long long val) {
            if (lo.empty() || val <= *prev(lo.end())) {
                lo.insert(val);
                sumLo += val;
            } else {
                hi.insert(val);
                sumHi += val;
            }
            rebalance();
        };
        auto remove = [&](long long val) {
            if (val <= *prev(lo.end())) {
                lo.erase(lo.find(val));
                sumLo -= val;
            } else {
                hi.erase(hi.find(val));
                sumHi -= val;
            }
            rebalance();
        };

        vector<long long> cost(n - x + 1);
        for (int i = 0; i < n; i++) {
            add(v[i]);
            if (i >= x) remove(v[i - x]);
            if (i >= x - 1) {
                long long med = *prev(lo.end());
                cost[i - x + 1] = med * (long long)lo.size() - sumLo + sumHi - med * (long long)hi.size();
            }
        }

        const long long INF = LLONG_MAX / 4;
        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, INF));
        for (int i = 0; i <= n; i++) dp[0][i] = 0;

        for (int j = 1; j <= k; j++) {
            for (int i = 1; i <= n; i++) {
                dp[j][i] = dp[j][i - 1];                    
                if (i >= x && dp[j - 1][i - x] < INF) {     
                    dp[j][i] = min(dp[j][i], dp[j - 1][i - x] + cost[i - x]);
                }
            }
        }
        return dp[k][n];
    }
};

/*
APPROCH :
Steps:
1. A window of size x is made equal at minimum cost by moving all its elements to the median.
2. Slide a window of size x over the array and keep it in two multisets: lo (smaller half) and hi (larger half), with sumLo and sumHi.
3. Median = largest element of lo. Cost of a window = med*|lo| - sumLo + sumHi - med*|hi|. Store it in cost[i] for the window starting at i.
4. dp[j][i] = minimum cost to pick j non-overlapping windows from the first i elements.
5. Transition: dp[j][i] = min(dp[j][i-1], dp[j-1][i-x] + cost[i-x]).
6. Answer = dp[k][n].

Time Complexity : O(n log x + n*k)
Space Complexity : O(n*k + x)

note: use long long for sums and costs, because values and totals can exceed int range.
*/