class Solution {
public:
    vector<int> findPairs(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, vector<pair<int, int>>> mp;

        // Store all index pairs according to their sum
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                mp[arr[i] + arr[j]].push_back({i, j});
            }
        }

        // Check pairs in lexicographical order
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {

                int sum = arr[i] + arr[j];

                auto &pairs = mp[sum];

                for(auto [c, d] : pairs) {

                    // Second pair must be lexicographically greater
                    if(make_pair(c, d) <= make_pair(i, j))
                        continue;

                    // All four indices must be distinct
                    if(i != c && i != d && j != c && j != d) {
                        return {i, j, c, d};
                    }
                }
            }
        }

        return {-1, -1, -1, -1};
    }
};