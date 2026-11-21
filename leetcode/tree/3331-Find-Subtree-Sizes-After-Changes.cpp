class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> original(n), modified(n);
        for (int i = 1; i < n; i++) {
            original[parent[i]].push_back(i);
        }
        vector<int> newParent = parent;
        vector<int> last(26, -1);
        function<void(int)> dfs1 = [&](int u) {
            int c = s[u] - 'a';

            int prev = last[c];
            if (last[c] != -1) {
                newParent[u] = last[c];
            }
            last[c] = u;
            for (int v : original[u]) {
                dfs1(v);
            }
            last[c] = prev;
        };

        dfs1(0);
        for (int i = 1; i < n; i++) {
            modified[newParent[i]].push_back(i);
        }
        vector<int> ans(n, 0);
        function<int(int)> dfs2 = [&](int u) {
            ans[u] = 1;
            for (int v : modified[u]) {
                ans[u] += dfs2(v);
            }
            return ans[u];
        };
        dfs2(0);
        return ans;
    }
};