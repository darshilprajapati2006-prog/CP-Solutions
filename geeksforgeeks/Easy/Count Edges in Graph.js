class Solution {
public:
    int countEdges(vector<vector<int>> &adj) {
        int cnt = 0;
        for (auto &v : adj) {
            cnt += v.size();
        }
        return cnt / 2;
    }
};