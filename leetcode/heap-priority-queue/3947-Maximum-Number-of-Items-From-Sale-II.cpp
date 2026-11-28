class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int maxFactor = n;
        int minPrice = INT_MAX;

        vector<int> freq(maxFactor + 1, 0);

        for (auto &item : items) {
            freq[item[0]]++;
            minPrice = min(minPrice, item[1]);
        }

        vector<int> gain(maxFactor + 1, 0);
        for (int f = 1; f <= maxFactor; f++) {
            int cnt = 0;
            for (int j = f; j <= maxFactor; j += f) {
                cnt += freq[j];
            }
            gain[f] = cnt - 1;
        }
        vector<pair<int, int>> deals;
        for (auto &item : items) {
            int factor = item[0];
            int price = item[1];

            if (gain[factor] > 0 && 1LL * price < 2LL * minPrice) {
                deals.push_back({price, gain[factor]});
            }
        }
        sort(deals.begin(), deals.end());

        long long ans = 0;
        long long remaining = budget;
        for (auto &[price, count] : deals) {
            long long buy = min(1LL * count, remaining / price);

            ans += 2 * buy;
            remaining -= buy * price;
        }
        ans += remaining / minPrice;

        return (int)ans;
    }
};