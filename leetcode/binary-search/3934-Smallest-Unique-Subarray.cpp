class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<map<int,int>> nxt(1);
        vector<int> link{-1}, len{0}, cnt{0};
        int last = 0;

        for (int c : nums) {
            int cur = nxt.size();
            nxt.emplace_back();
            len.push_back(len[last] + 1);
            link.push_back(-1);
            cnt.push_back(1);

            int p = last;
            while (p != -1 && !nxt[p].count(c)) {
                nxt[p][c] = cur;
                p = link[p];
            }
            if (p == -1) {
                link[cur] = 0;
            } else {
                int q = nxt[p][c];
                if (len[p] + 1 == len[q]) {
                    link[cur] = q;
                } else {
                    int cl = nxt.size();
                    map<int,int> copy = nxt[q];
                    nxt.push_back(copy);
                    len.push_back(len[p] + 1);
                    link.push_back(link[q]);
                    cnt.push_back(0);
                    while (p != -1 && nxt[p].count(c) && nxt[p][c] == q) {
                        nxt[p][c] = cl;
                        p = link[p];
                    }
                    link[q] = link[cur] = cl;
                }
            }
            last = cur;
        }

        int m = nxt.size();

        // counting sort of states by len
        vector<int> bucket(n + 2, 0), order(m);
        for (int v = 0; v < m; v++) bucket[len[v]]++;
        for (int i = 1; i <= n; i++) bucket[i] += bucket[i - 1];
        for (int v = m - 1; v >= 0; v--) order[--bucket[len[v]]] = v;

        // push occurrence counts up the suffix links (longest first)
        for (int i = m - 1; i >= 1; i--) {
            int v = order[i];
            cnt[link[v]] += cnt[v];
        }

        // states with exactly 1 occurrence: shortest unique length = len[link]+1
        int ans = n;
        for (int v = 1; v < m; v++)
            if (cnt[v] == 1) ans = min(ans, len[link[v]] + 1);

        return ans;
    }
};