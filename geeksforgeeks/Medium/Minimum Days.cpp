class Solution {
  public:
    int getMinimumDays(string s, vector<int>& p) {
        int n = s.size();
        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            pos[p[i]] = i;
        }
        int ans = 0;
        for (int i = 0; i + 1 < n; i++) {
            if (s[i] == s[i + 1]) {                       
                int day = min(pos[i], pos[i + 1]) + 1; 
                ans = max(ans, day);
            }
        }
        return ans;
    }
};