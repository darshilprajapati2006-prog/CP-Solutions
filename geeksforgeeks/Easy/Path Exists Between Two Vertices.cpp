class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int node, int v, vector<bool>& vis) {
        if (node == v) return true;

        vis[node] = true;

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                if (dfs(adj, nei, v, vis))
                    return true;
            }
        }
        return false;
    }
    bool checkPath(vector<vector<int>>& adj, int u, int v) {
        vector<bool> vis(adj.size(), false);
        return dfs(adj, u, v, vis);
    }
};