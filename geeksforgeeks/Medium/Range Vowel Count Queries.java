class Solution {
public:
    vector<int> countVowels(string &s, vector<vector<int>> &queries) {
        int n = s.size();
        vector<int> pref(n + 1, 0);
        vector<int> ans;

        auto isVowel = [&](char c) {
            return c == 'a' || c == 'e' || c == 'i' ||
                   c == 'o' || c == 'u';
        };

        // Build prefix sum
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + isVowel(s[i]);
        }

        // Answer queries
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            ans.push_back(pref[r + 1] - pref[l]);
        }

        return ans;
    }
};