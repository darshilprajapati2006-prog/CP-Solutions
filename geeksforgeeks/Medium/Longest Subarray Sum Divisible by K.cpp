class Solution {
public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1;

        long long prefixSum = 0;
        int ans = 0;

        for (int i = 0; i < arr.size(); i++) {
            prefixSum += arr[i];

            int rem = prefixSum % k;
            if (rem < 0) rem += k;

            if (mp.count(rem)) {
                ans = max(ans, i - mp[rem]);
            }
            else {
                mp[rem] = i;
            }
        }

        return ans;
    }
};