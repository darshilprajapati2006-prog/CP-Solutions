class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for(int i = 0; i < n; i++) {
            int sum[4] = {0};
            int mn[4] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
            int mx[4] = {0};

            for(int j = i; j < n; j++) {
                int x = nums[j];
                int cnt[4] = {0};

                int primes[4] = {2, 3, 5, 7};

                for(int k = 0; k < 4; k++) {
                    while(x % primes[k] == 0) {
                        cnt[k]++;
                        x /= primes[k];
                    }
                }

                bool valid = true;

                for(int k = 0; k < 4; k++) {
                    sum[k] += cnt[k];
                    mn[k] = min(mn[k], cnt[k]);
                    mx[k] = max(mx[k], cnt[k]);

                    if(sum[k] != mn[k] + mx[k])
                        valid = false;
                }

                if(valid)
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};