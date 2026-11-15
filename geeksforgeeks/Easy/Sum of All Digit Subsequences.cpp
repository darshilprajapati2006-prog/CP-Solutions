class Solution {
  public:
    int subsequenceSum(string &s) {
        const long long MOD = 1e9 + 7;
        long long sum = 0;

        for (char c : s) {
            sum += (c - '0');
        }

        long long ways = 1;

        for (int i = 1; i < s.size(); i++) {
            ways = (ways * 2) % MOD;
        }

        return (sum % MOD * ways) % MOD;
    }
};
